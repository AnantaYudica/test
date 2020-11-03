#include "test/out/print/fp/Exponent.h"

#include <cassert>
#include <cstring>

int main()
{
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "e+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "e+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e+00000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "e+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "e+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e+00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "e-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "e-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e-00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "e+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "e+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e+00000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "e+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "e+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e+00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "e-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "e-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e-00000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "e+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "e+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e+00000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "e+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "e+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e+00000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "e-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "e-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "e-00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "p+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "p+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p+00000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "p+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "p+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p+00000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "p-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "p-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p-00000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "p+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "p+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p+00000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "p+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "p+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p+00000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "p-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "p-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p-00000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "p+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "p+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p+00000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "p+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "p+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p+00000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "p-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "p-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "p-00000039") == 0);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "E+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "E+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E+00000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "E+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "E+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E+00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "E-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "E-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E-00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "E+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "E+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E+00000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "E+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "E+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E+00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "E-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "E-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E-00000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "E+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "E+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E+00000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "E+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "E+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E+00000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "E-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "E-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "E-00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "P+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "P+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P+00000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "P+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "P+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P+00000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "P-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "P-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P-00000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "P+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "P+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P+00000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "P+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "P+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P+00000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "P-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "P-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P-00000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "P+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "P+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P+00000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "P+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "P+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P+00000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(strcmp(*cstr1, "P-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(strcmp(*cstr2, "P-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "P-00000039") == 0);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 2);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "00") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000039") == 0);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(strcmp(*cstr2, "12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(strcmp(*cstr1, "1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(strcmp(*cstr2, "1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(strcmp(*cstr1, "41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "0000000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(strcmp(*cstr1, "-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(strcmp(*cstr2, "-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<char, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(strcmp(*cstr3, "-000000039") == 0);
    }
    //// WCHAR
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"e+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"e+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e+00000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"e+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"e+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e+00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"e-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"e-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e-00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"e+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"e+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e+00000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"e+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"e+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e+00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"e-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"e-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e-00000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"e+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"e+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e+00000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"e+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"e+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e+00000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"e-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"e-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"e-00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"p+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"p+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p+00000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"p+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"p+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p+00000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"p-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"p-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p-00000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"p+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"p+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p+00000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"p+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"p+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p+00000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"p-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"p-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p-00000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"p+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"p+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p+00000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"p+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"p+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p+00000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"p-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"p-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"p-00000039") == 0);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"E+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"E+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E+00000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"E+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"E+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E+00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"E-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"E-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E-00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"E+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"E+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E+00000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"E+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"E+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E+00000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"E-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"E-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E-00000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"E+0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"E+0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E+00000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"E+12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"E+12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E+00000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"E-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"E-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"E-00000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"P+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"P+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P+00000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"P+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"P+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P+00000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"P-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"P-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P-00000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"P+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"P+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P+00000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"P+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"P+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P+00000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"P-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"P-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P-00000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"P+1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"P+1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P+00000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"P+41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"P+41") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P+00000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 4);
        assert(wcscmp(*cstr1, L"P-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 4);
        assert(wcscmp(*cstr2, L"P-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"P-00000039") == 0);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 2);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"00") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, true, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000039") == 0);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>());
        assert(cstr1.Size() == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2.Size() == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, false>(), 10);
        assert(cstr3.Size() == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000000") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000000") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000012") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000012") == 0);
    }
    
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"0") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"0") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000000") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 2);
        assert(wcscmp(*cstr2, L"12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000012") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-12") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-12") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<10, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000012") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000001") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e+12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000041") == 0);
    }
    {
        test::FloatingPoint<float> fp1{3.14e-12f};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000039") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000001") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e+12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000041") == 0);
    }
    {
        test::FloatingPoint<double> fp1{3.14e-12};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000039") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 1);
        assert(wcscmp(*cstr1, L"1") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2.Size() == 1);
        assert(wcscmp(*cstr2, L"1") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000001") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e+12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 2);
        assert(wcscmp(*cstr1, L"41") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"041") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"0000000041") == 0);
    }
    {
        test::FloatingPoint<long double> fp1{3.14e-12L};
        auto cstr1 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>());
        assert(cstr1.Size() == 3);
        assert(wcscmp(*cstr1, L"-39") == 0);

        auto cstr2 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 3);
        assert(cstr2.Size() == 3);
        assert(wcscmp(*cstr2, L"-39") == 0);
        
        auto cstr3 = test::out::print::fp::Exponent::
            CStr<wchar_t, false, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr3.Size() == 10);
        assert(wcscmp(*cstr3, L"-000000039") == 0);
    }
    return 0;
}