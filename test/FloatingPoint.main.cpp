
#include "test/FloatingPoint.h"

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cfloat>
#include <cinttypes>
#include <cstdio>

#if FLT_MANT_DIG == 24
#define PRFExp PRId16
#define PRFMant PRIu32
#elif FLT_MANT_DIG == 53
#define PRFExp PRId16
#define PRFMant PRIu64
#elif FLT_MANT_DIG == 64
#define PRFExp PRId16
#define PRFMant PRIu64
#else
    #error "FLT_MANT_DIG no condition"
#endif

#if DBL_MANT_DIG == 24
#define PRDExp PRId16
#define PRDMant PRIu32
#elif DBL_MANT_DIG == 53
#define PRDExp PRId16
#define PRDMant PRIu64
#elif DBL_MANT_DIG == 64
#define PRDExp PRId16
#define PRDMant PRIu64
#else
    #error "DBL_MANT_DIG no condition"
#endif

#if LDBL_MANT_DIG == 24
#define PRLDExp PRId16
#define PRLDMant PRIu32
#elif LDBL_MANT_DIG == 53
#define PRLDExp PRId16
#define PRLDMant PRIu64
#elif LDBL_MANT_DIG == 64
#define PRLDExp PRId16
#define PRLDMant PRIu64
#else
    #error "LDBL_MANT_DIG no condition"
#endif

template<typename TFloat>
static int MaxDigit()
{
    typedef test::fp::Base<10, test::FloatingPoint<TFloat>> Base10Type;
    TFloat ndigit_f = Base10Type::BitSizeMantissa();
    ndigit_f *= Base10Type::Log();
    const int ndigit = std::floor(ndigit_f);
    return (ndigit - 
        (ndigit == 6 ? 2 : 
        (ndigit == 15 ? 3 : 
        (ndigit == 18 ? 4 : 0))));
}

template<typename TFloat>
static constexpr TFloat Random(TFloat val = 0.0f, 
    int ndigit = MaxDigit<TFloat>(), int i = 0)
{
    return (ndigit == i ? val : 
        Random<TFloat>((val * 10) + (int)rand() % 10, ndigit, i + 1));
}

int main()
{
    srand (time(NULL));
    {
        test::FloatingPoint<float> fl;
        assert(fl.IsSign() == false);
        assert(fl.GetExponent() == (fl.MinimumExponent() - 1));
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetSign(true);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == (fl.MinimumExponent() - 1));
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetExponent(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == 0);
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetExponent(fl.MinimumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MinimumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetExponent(fl.MaximumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetMantissa(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == (fl.MinimumNormalMantissa() | 0));
        assert(fl.GetSubNormalMantissa() == 0);
        
        fl.SetMantissa(fl.MinimumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.MaximumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MaximumSubNormalMantissa());
        
        fl.SetMantissa(fl.MinimumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.MaximumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MaximumSubNormalMantissa());
    }
    {
        typedef test::FloatingPoint<float>::MantissaType MantissaType;
        test::FloatingPoint<float> fl1(3.14f);
        assert(fl1.GetFloat() == 3.14f);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        float f1 = 3.14f;
        MantissaType mant_byte1 = reinterpret_cast<MantissaType&>(f1);
        mant_byte1 &= fl1.MaximumSubNormalMantissa();
        assert(fl1.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);
        
        test::FloatingPoint<float> fl2(-3.14f);
        assert(fl2.GetFloat() == -3.14f);
        assert(fl2.IsSign() == true);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        assert(fl2.GetNormalMantissa() == (fl2.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
        assert(fl2.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        typedef test::FloatingPoint<float>::SignedIntegerType IntegerType;
        typedef test::FloatingPoint<float>::SignedIntegerType 
            UnsignedIntegerType;
        typedef test::FloatingPoint<float>::MantissaType MantissaType;
        test::FloatingPoint<float> fl1{(UnsignedIntegerType)314};
        assert(fl1.GetFloat() == 314.0f);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(314)));

        float f1 = 314.0f;
        MantissaType mant_byte1 = reinterpret_cast<MantissaType&>(f1);
        mant_byte1 &= fl1.MaximumSubNormalMantissa();

        assert(fl1.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);

        test::FloatingPoint<float> fl2{(IntegerType)-314};
        assert(fl2.GetFloat() == -314.0f);
        assert(fl2.IsSign() == true);
        assert(fl2.GetExponent() == floor(log2(314)));
        assert(fl2.GetNormalMantissa() == (fl2.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        test::FloatingPoint<double> fl;
        assert(fl.IsSign() == false);
        assert(fl.GetExponent() == (fl.MinimumExponent() - 1));
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetSign(true);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == (fl.MinimumExponent() - 1));
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetExponent(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == 0);
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetExponent(fl.MinimumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MinimumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetExponent(fl.MaximumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetMantissa(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == (fl.MinimumNormalMantissa() | 0));
        assert(fl.GetSubNormalMantissa() == 0);
        
        fl.SetMantissa(fl.MinimumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.MaximumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MaximumSubNormalMantissa());
        
        fl.SetMantissa(fl.MinimumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.MaximumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MaximumSubNormalMantissa());
    }
    {
        typedef test::FloatingPoint<double>::MantissaType MantissaType;
        test::FloatingPoint<double> fl1(3.14);
        assert(fl1.GetFloat() == 3.14);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        double f1 = 3.14;
        MantissaType mant_byte1 = reinterpret_cast<MantissaType&>(f1);
        mant_byte1 &= fl1.MaximumSubNormalMantissa();
        assert(fl1.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);
        
        
        test::FloatingPoint<double> fl2(-3.14);
        assert(fl2.GetFloat() == -3.14);
        assert(fl2.IsSign() == true);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        assert(fl2.GetNormalMantissa() == (fl2.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
        assert(fl2.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    
    {
        typedef test::FloatingPoint<double>::SignedIntegerType IntegerType;
        typedef test::FloatingPoint<double>::SignedIntegerType 
            UnsignedIntegerType;
        typedef test::FloatingPoint<double>::MantissaType MantissaType;
        test::FloatingPoint<double> fl1{(UnsignedIntegerType)314};
        assert(fl1.GetFloat() == 314.0);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(314)));

        double f1 = 314.0;
        MantissaType mant_byte1 = reinterpret_cast<MantissaType&>(f1);
        mant_byte1 &= fl1.MaximumSubNormalMantissa();

        assert(fl1.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);

        test::FloatingPoint<double> fl2{(IntegerType)-314};
        assert(fl2.GetFloat() == -314.0);
        assert(fl2.IsSign() == true);
        assert(fl2.GetExponent() == floor(log2(314)));
        assert(fl2.GetNormalMantissa() == (fl2.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        test::FloatingPoint<long double> fl;
        assert(fl.IsSign() == false);
        assert(fl.GetExponent() == (fl.MinimumExponent() -1));
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetSign(true);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == (fl.MinimumExponent() -1));
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetExponent(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == 0);
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetExponent(fl.MinimumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MinimumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetExponent(fl.MaximumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());

        fl.SetMantissa(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == (fl.MinimumNormalMantissa() | 0));
        assert(fl.GetSubNormalMantissa() == 0);
        
        fl.SetMantissa(fl.MinimumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.MaximumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MaximumSubNormalMantissa());
        
        fl.SetMantissa(fl.MinimumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.MaximumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.MaximumExponent());
        assert(fl.GetNormalMantissa() == fl.MaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.MaximumSubNormalMantissa());
    }
    {
        typedef test::FloatingPoint<long double>::MantissaType MantissaType;
        test::FloatingPoint<long double> fl1(3.14L);
        assert(fl1.GetFloat() == 3.14L);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(3.14L)));
        long double f1 = 3.14L;
        MantissaType mant_byte1 = reinterpret_cast<MantissaType&>(f1);
        mant_byte1 &= fl1.MaximumSubNormalMantissa();
        assert(fl1.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);
        
        
        test::FloatingPoint<long double> fl2(-3.14L);
        assert(fl2.GetFloat() == -3.14L);
        assert(fl2.IsSign() == true);
        assert(fl1.GetExponent() == floor(log2(3.14L)));
        assert(fl2.GetNormalMantissa() == (fl2.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
        assert(fl2.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        typedef test::FloatingPoint<long double>::SignedIntegerType 
            IntegerType;
        typedef test::FloatingPoint<long double>::SignedIntegerType 
            UnsignedIntegerType;
        typedef test::FloatingPoint<long double>::MantissaType MantissaType;
        test::FloatingPoint<long double> fl1{(UnsignedIntegerType)314};

        assert(fl1.GetFloat() == 314.0L);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(314)));

        long double f1 = 314.0L;
        MantissaType mant_byte1 = reinterpret_cast<MantissaType&>(f1);
        mant_byte1 &= fl1.MaximumSubNormalMantissa();

        assert(fl1.GetNormalMantissa() == (fl1.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);

        test::FloatingPoint<long double> fl2{(IntegerType)-314};
        assert(fl2.GetFloat() == -314.0L);
        assert(fl2.IsSign() == true);
        assert(fl2.GetExponent() == floor(log2(314)));
        assert(fl2.GetNormalMantissa() == (fl2.MinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        float f1 = 0.314f;
        float f1_int = f1 * std::pow(10, 3);
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    {
        float f1 = 314.0f;
        float f1_int = f1 * std::pow(10, 1);
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    {
        const float f1_int = 0.0f;
        int pn = 0;
        float f1 = f1_int * std::pow(10, pn);
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<float>::MinimumExponent()) + MaxDigit<float>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<float>::MaximumExponent()) - MaxDigit<float>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        float f1_int = 0.0f;
        while(f1_int == 0.0f) f1_int = Random<float>();
        float f1 = f1_int * std::pow((float)10, pn);
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow((float)2, exp_base);
            val *= std::pow((float)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %f\n", f1);
                printf("val %f\n", val);
                printf("f1_int %f\n", f1_int);
            }
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow((float)10, exp_base);
            val *= std::pow((float)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %f\n", f1);
                printf("val %f\n", val);
                printf("f1_int %f\n", f1_int);
            }
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float val = mant_base;
            val *= std::pow((float)16, exp_base);
            val *= std::pow((float)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %f\n", f1);
                printf("val %f\n", val);
                printf("f1_int %f\n", f1_int);
            }
            assert(val == f1_int);
        }
    }
    ///
    {
        double f1 = 0.314;
        double f1_int = f1 * std::pow(10, 3);
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    {
        double f1 = 314.0;
        double f1_int = f1 * std::pow(10, 1);
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    {
        const double f1_int = 0.0;
        int pn = 0;
        double f1 = f1_int * std::pow(10, pn);
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<double>::MinimumExponent()) + MaxDigit<double>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<double>::MaximumExponent()) - MaxDigit<double>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        double f1_int = 0.0;
        while(f1_int == 0.0) f1_int = Random<double>();
        double f1 = f1_int * std::pow((double)10, pn);
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow((double)2, exp_base);
            val *= std::pow((double)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %f\n", f1);
                printf("val %f\n", val);
                printf("f1_int %f\n", f1_int);
            }
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow((double)10, exp_base);
            val *= std::pow((double)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %f\n", f1);
                printf("val %f\n", val);
                printf("f1_int %f\n", f1_int);
            }
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double val = mant_base;
            val *= std::pow((double)16, exp_base);
            val *= std::pow((double)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %f\n", f1);
                printf("val %f\n", val);
                printf("f1_int %f\n", f1_int);
            }
            assert(val == f1_int);
        }
    }
    ///
    {
        long double f1 = 0.314L;
        long double f1_int = f1 * std::pow(10, 3);
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, 3);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    {
        long double f1 = 314.0L;
        long double f1_int = f1 * std::pow(10, 1);
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, 1);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    
    {
        const long double f1_int = 0.0L;
        int pn = 0;
        long double f1 = f1_int * std::pow(10, pn);
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(2, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(10, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow(16, exp_base);
            val *= std::pow(10, -pn);
            val = std::round(val);
            assert(val == f1_int);
        }
    }
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<long double>::MinimumExponent()) + 
            MaxDigit<long double>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<long double>::MaximumExponent()) - 
            MaxDigit<long double>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        long double f1_int = 0.0L;
        while(f1_int == 0.0L) f1_int = Random<long double>();
        long double f1 = f1_int * std::pow((long double)10, pn);
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow((long double)2, exp_base);
            val *= std::pow((long double)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %Lf\n", f1);
                printf("val %Lf\n", val);
                printf("f1_int %Lf\n", f1_int);
            }
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow((long double)10, exp_base);
            val *= std::pow((long double)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %Lf\n", f1);
                printf("val %Lf\n", val);
                printf("f1_int %Lf\n", f1_int);
            }
            assert(val == f1_int);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double val = mant_base;
            val *= std::pow((long double)16, exp_base);
            val *= std::pow((long double)10, -pn);
            val = std::round(val);
            if(val != f1_int)
            {
                printf("i %d\n", i);
                printf("pn %d\n", pn);
                printf("f1 %Lf\n", f1);
                printf("val %Lf\n", val);
                printf("f1_int %Lf\n", f1_int);
            }
            assert(val == f1_int);
        }
    }
    //// SUBNORMAL
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<float>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const float mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<float>::
            MinimumExponent() - (test::FloatingPoint<float>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<float>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<float>::MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            assert(exp_bin == exp_base);
            assert(mant_bin_f == mant_base);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float exp_b10_f = exp_bin;
            exp_b10_f *=(std::log((float)2)/std::log((float)10));
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (float)exp_b10;
            exp_b10 *= -1;
            float mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((float)10, exp_b10_f);

            assert(exp_base == exp_b10);
            assert(mant_base == mant_b10_f);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            float exp_b16_f = (std::log((float)2)/std::log((float)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (float)exp_b16;
            exp_b16 *= -1;
            float mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((float)16, exp_b16_f);

            assert(exp_base == exp_b16);
            assert(mant_base == mant_b16_f);
        }
    }
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<float>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<float>::
            BitFieldMantissa();
        const float mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<float>::
            MinimumExponent() - (test::FloatingPoint<float>::
            BitFieldMantissa() + test::FloatingPoint<float>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<float>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<float>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            assert(exp_bin == exp_base);
            assert(mant_bin_f == mant_base);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float exp_b10_f = (std::log((float)2)/std::log((float)10)) * 
                (float)exp_bin;
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (float)exp_b10;
            exp_b10 *= -1;
            float mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((float)10, exp_b10_f);

            assert(exp_base == exp_b10);
            assert(mant_base == mant_b10_f);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            float exp_b16_f = (std::log((float)2)/std::log((float)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (float)exp_b16;
            exp_b16 *= -1;
            float mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((float)16, exp_b16_f);

            assert(exp_base == exp_b16);
            assert(mant_base == mant_b16_f);
        }
    }
    ///
    {
        typedef typename test::FloatingPoint<double>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType ExponentType;
        test::FloatingPoint<double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<double>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<double>::
            MinimumExponent() - (test::FloatingPoint<double>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<double>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<double>::MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            assert(exp_bin == exp_base);
            assert(mant_bin_f == mant_base);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            double exp_b10_f = exp_bin;
            exp_b10_f *= fp_base.Log();
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (double)exp_b10;
            exp_b10 *= -1;

            double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((double)10, exp_b10_f);
            
            assert(exp_base == exp_b10);
            assert(mant_base == mant_b10_f);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            double exp_b16_f = (std::log((double)2)/std::log((double)16)) * 
                (double)exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (double)exp_b16;
            exp_b16 *= -1;
            double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((double)16, exp_b16_f);

            assert(exp_base == exp_b16);
            assert(mant_base == mant_b16_f);
        }
    }
    {
        typedef typename test::FloatingPoint<double>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType ExponentType;
        test::FloatingPoint<double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<double>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<double>::
            BitFieldMantissa();
        const double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<double>::
            MinimumExponent() - (test::FloatingPoint<double>::
            BitFieldMantissa() + test::FloatingPoint<double>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<double>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<double>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            assert(exp_bin == exp_base);
            assert(mant_bin_f == mant_base);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double exp_b10_f = (std::log(2)/std::log((double)10)) * 
                (double)exp_bin;
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (double)exp_b10;
            exp_b10 *= -1;
            double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((double)10, exp_b10_f);

            assert(exp_base == exp_b10);
            assert(mant_base == mant_b10_f);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            double exp_b16_f = (std::log(2)/std::log((double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (double)exp_b16;
            exp_b16 *= -1;
            double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((double)16, exp_b16_f);

            assert(exp_base == exp_b16);
            assert(mant_base == mant_b16_f);
        }
    }
    ///
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        test::FloatingPoint<long double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<long double>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const long double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<long double>::
            MinimumExponent() - (test::FloatingPoint<long double>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<long double>::
            MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<long double>::
            MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            assert(exp_bin == exp_base);
            assert(mant_bin_f == mant_base);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double exp_b10_f = exp_bin;
            exp_b10_f *=(std::log((long double)2)/std::log((long double)10));
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (long double)exp_b10;
            exp_b10 *= -1;
            long double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((long double)10, exp_b10_f);

            assert(exp_base == exp_b10);
            assert(mant_base == mant_b10_f);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            long double exp_b16_f = 
                (std::log((long double)2)/std::log((long double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (long double)exp_b16;
            exp_b16 *= -1;
            long double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((long double)16, exp_b16_f);

            assert(exp_base == exp_b16);
            assert(mant_base == mant_b16_f);
        }
    }
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        test::FloatingPoint<long double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<long double>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<long double>::
            BitFieldMantissa();
        const long double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<long double>::
            MinimumExponent() - (test::FloatingPoint<long double>::
            BitFieldMantissa() + test::FloatingPoint<long double>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<long double>::
            MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<long double>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            assert(exp_bin == exp_base);
            assert(mant_bin_f == mant_base);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double exp_b10_f = 
                (std::log((long double)2)/std::log((long double)10)) * 
                    (long double)exp_bin;
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (long double)exp_b10;
            exp_b10 *= -1;
            long double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((long double)10, exp_b10_f);

            assert(exp_base == exp_b10);
            assert(mant_base == mant_b10_f);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            long double exp_b16_f = 
                (std::log((long double)2)/std::log((long double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (long double)exp_b16;
            exp_b16 *= -1;
            long double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((long double)16, exp_b16_f);

            assert(exp_base == exp_b16);
            assert(mant_base == mant_b16_f);
        }
    }
    ///
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1{314.0f};
        int int_val = 314;

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base2 = fl1_num.GetRemainder();
            rem_base2 *= std::pow((float)2, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() <= 0);
            assert(rem_base2 < 0.5f);
            assert(fl1_num.GetInteger() == 314);

            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetIntegerDigitSize() == 9);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base10 = fl1_num.GetRemainder();
            rem_base10 *= std::pow((float)10, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() <= 0);
            assert(rem_base10 < 0.5f);
            assert(fl1_num.GetInteger() == 314);

            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetIntegerDigitSize() == 3);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base16 = fl1_num.GetRemainder();
            rem_base16 *= std::pow((float)16, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() <= 0);
            assert(rem_base16 < 0.5f);
            assert(fl1_num.GetInteger() == 314);

            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetIntegerDigitSize() == 3);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
        }
    }
    {
        test::FloatingPoint<float> fl1{0.314f};

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base2 = fl1_num.GetRemainder();
            rem_base2 *= std::pow((float)2, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() < 0);
            assert(rem_base2 < 0.3145f);
            assert(rem_base2 > 0.3135f);
            assert(fl1_num.GetInteger() == 0);
            
            auto rem_ndigit = test::bit::index::Big(fl1_num.GetRemainder()) + 1;
            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base10 = fl1_num.GetRemainder();
            rem_base10 *= std::pow((float)10, fl1_num.GetExponent());
            
            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() < 0);
            assert(rem_base10 < 0.3145f);
            assert(rem_base10 > 0.3135f);
            assert(fl1_num.GetInteger() == 0);
            
            float rem_ndigit = 1;
            if (fl1_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log(fl1_num.GetRemainder());
                rem_ndigit /= std::log((float) 10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }
            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base16 = fl1_num.GetRemainder();
            rem_base16 *= std::pow((float)16, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() < 0);
            assert(rem_base16 < 0.3145f);
            assert(rem_base16 > 0.3135f);
            assert(fl1_num.GetInteger() == 0);
            
            float rem_ndigit = 1;
            if (fl1_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log(fl1_num.GetRemainder());
                rem_ndigit /= std::log((float) 16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    {
        test::FloatingPoint<float> fl1{3.14f};

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base2 = fl1_num.GetRemainder();
            rem_base2 *= std::pow((float)2, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() < 0);
            assert(rem_base2 < 0.145f);
            assert(rem_base2 > 0.135f);
            assert(fl1_num.GetInteger() == 3);
            
            auto rem_ndigit = 
                test::bit::index::Big(fl1_num.GetRemainder()) + 1;
            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
            assert(fl1_num.GetIntegerDigitSize() == 2);
            assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base10 = fl1_num.GetRemainder();
            rem_base10 *= std::pow((float)10, fl1_num.GetExponent());
            
            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() < 0);
            assert(rem_base10 < 0.145f);
            assert(rem_base10 > 0.135f);
            assert(fl1_num.GetInteger() == 3);
            
            float rem_ndigit = 1;
            if (fl1_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log(fl1_num.GetRemainder());
                rem_ndigit /= std::log((float) 10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
            assert(fl1_num.GetIntegerDigitSize() == 1);
            assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base16 = fl1_num.GetRemainder();
            rem_base16 *= std::pow((float)16, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_NORMAL);
            assert(fl1_num.GetExponent() < 0);
            assert(rem_base16 < 0.145f);
            assert(rem_base16 > 0.135f);
            assert(fl1_num.GetInteger() == 3);
            
            float rem_ndigit = 1;
            if (fl1_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log(fl1_num.GetRemainder());
                rem_ndigit /= std::log((float) 16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fl1_num.GetIntegerDigitSize() >= 0);
            assert(fl1_num.GetRemainderDigitSize() >= 0);
            assert(fl1_num.GetIntegerDigitSize() == 1);
            assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    
    {
        test::FloatingPoint<float> fl1{};

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base2 = fl1_num.GetRemainder();
            rem_base2 *= std::pow((float)2, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_ZERO);
            assert(fl1_num.GetExponent() == 0);
            assert(rem_base2 == 0);
            assert(fl1_num.GetInteger() == 0);
            
            assert(fl1_num.GetIntegerDigitSize() == 0);
            assert(fl1_num.GetRemainderDigitSize() == 0);
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base10 = fl1_num.GetRemainder();
            rem_base10 *= std::pow((float)10, fl1_num.GetExponent());
            
            assert(fl1_base.Classify() == FP_ZERO);
            assert(fl1_num.GetExponent() == 0);
            assert(rem_base10 == 0);
            assert(fl1_num.GetInteger() == 0);
            
            assert(fl1_num.GetIntegerDigitSize() == 0);
            assert(fl1_num.GetRemainderDigitSize() == 0);
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            float rem_base16 = fl1_num.GetRemainder();
            rem_base16 *= std::pow((float)16, fl1_num.GetExponent());

            assert(fl1_base.Classify() == FP_ZERO);
            assert(fl1_num.GetExponent() == 0);
            assert(rem_base16 == 0);
            assert(fl1_num.GetInteger() == 0);
            
            assert(fl1_num.GetIntegerDigitSize() == 0);
            assert(fl1_num.GetRemainderDigitSize() == 0);
        }
    }
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<float>::MinimumExponent()) + MaxDigit<float>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<float>::MaximumExponent()) - 
            MaxDigit<float>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        float f1_int = 0.0f;
        while(f1_int == 0.0f) f1_int = Random<float>();
        float f1 = f1_int * std::pow((float)10, pn);
        test::FloatingPoint<float> fl1{f1};
        auto mant = fl1.GetNormalMantissa();
        auto exp = fl1.GetExponent();

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            auto exp_base2 = exp;
            exp_base2 -= fl1_base.BitSizeMantissa();

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {
                if (fl1_num.GetExponent() != exp_base2)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("exp2 %" PRFExp "\n", exp_base2);
                    printf("base exp %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base2);

                if (fl1_num.GetInteger() != mant)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                float int_ndigit = 
                    test::bit::index::Big(fl1_num.GetInteger());
                int_ndigit = std::floor(int_ndigit) + 1;

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base int digit size %" PRFExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %f\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base rem digit size %" PRFExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base exp %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    float int_val_f = mant;
                    int_val_f *= std::pow((float)2, exp_base2);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRFMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    float int_ndigit = 
                        test::bit::index::Big(fl1_num.GetInteger());
                    int_ndigit += 1;

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base int digit size %" PRFExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base rem digit size %" PRFExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant;
                    int_val *= std::pow((float)2, exp_base2);

                    float rem_val_f = (f1 - int_val);
                    rem_val_f *= std::pow((float)2, 
                        -fl1_num.GetExponent());
                    rem_val_f = std::round(rem_val_f);

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRFMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val_f)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                        printf("rem val %f\n", rem_val_f);
                    }
                    assert(fl1_num.GetRemainder() == rem_val_f);
                    
                    float int_ndigit = 
                        test::bit::index::Big(fl1_num.GetInteger());
                    int_ndigit = std::floor(int_ndigit) + 1;
                    float rem_ndigit = 
                        test::bit::index::Big(fl1_num.GetRemainder());
                    rem_ndigit = std::floor(rem_ndigit) + 1;

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base int digit size %" PRFExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("base rem digit size %" PRFExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %f\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base2)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("exp2 %" PRFExp "\n", exp_base2);
                    printf("base exp : %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base2);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base int : %" PRFMant"\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base rem : %" PRFMant"\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant);
                
                float rem_ndigit = 
                    test::bit::index::Big(fl1_num.GetRemainder());
                rem_ndigit = std::floor(rem_ndigit) + 1;

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base int digit size : %" PRFExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("base rem digit size : %" PRFExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem digit size : %f\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            float exp_base10_f = exp - fl1_base.BitSizeMantissa();
            exp_base10_f *= (std::log((float)2)/std::log((float)10));

            ExponentType exp_base10 = std::floor(std::abs(exp_base10_f));
            float exp_index_f = std::abs(exp_base10_f);
            exp_index_f -= (float)exp_base10;
            if (exp_base10_f < 0)
            {
                exp_index_f = exp_base10_f + (float)exp_base10;
                exp_base10 *= -1;
            }
            else if(exp_index_f != 0)
            {
                exp_index_f = exp_base10_f - (float)exp_base10;
                exp_index_f -= 1;
                exp_base10 += 1;
            }

            float mant_base10_f = mant;
            mant_base10_f *= std::pow((float)10, exp_index_f);
            MantissaType mant_base10 = std::floor(mant_base10_f);

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {
                if (fl1_num.GetExponent() != exp_base10)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base exp %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base10);

                if (fl1_num.GetInteger() != mant_base10)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant_base10);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                float int_ndigit = 1;
                if (fl1_num.GetInteger() != 0)
                {
                    int_ndigit = std::log((float)fl1_num.GetInteger());
                    int_ndigit /= std::log((float)10);
                    int_ndigit = std::floor(int_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("int : %" PRFMant "\n", fl1_num.GetInteger());
                    printf("base int digit size %" PRFExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %f\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base rem digit size %" PRFExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base exp %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    float int_val_f = mant_base10;
                    int_val_f *= std::pow((float)10, exp_base10);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRFMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    float int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((float)fl1_num.GetInteger());
                        int_ndigit /= std::log((float)10);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("int : %" PRFMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRFExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("base rem digit size %" PRFExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant_base10;
                    int_val *= std::pow((float)10, exp_base10);
                    MantissaType rem_val = (MantissaType)(mant_base10 - 
                        (int_val * (MantissaType)(std::pow((float)10, 
                        -fl1_num.GetExponent()))));

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRFMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                        printf("rem val %" PRFMant "\n", rem_val);
                    }
                    assert(fl1_num.GetRemainder() == rem_val);
                    
                    float int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((float)fl1_num.GetInteger());
                        int_ndigit /= std::log((float)10);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }
                    float rem_ndigit = 1;
                    if (fl1_num.GetRemainder() != 0)
                    {
                        rem_ndigit = std::log((float)fl1_num.GetRemainder());
                        rem_ndigit /= std::log((float)10);
                        rem_ndigit = std::floor(rem_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("int : %" PRFMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRFExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant10 %" PRFMant "\n", mant_base10);
                        printf("exp10 %" PRFExp "\n", exp_base10);
                        printf("rem : %" PRFMant "\n", fl1_num.GetRemainder());
                        printf("base rem digit size %" PRFExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %f\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base10)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base exp : %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base10);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base int : %" PRFMant"\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant_base10)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base rem : %" PRFMant"\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant_base10);
                
                float rem_ndigit = 1;
                if (fl1_num.GetRemainder() != 0)
                {
                    rem_ndigit = std::log((float)fl1_num.GetRemainder());
                    rem_ndigit /= std::log((float)10);
                    rem_ndigit = std::floor(rem_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base int digit size : %" PRFExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant10 %" PRFMant "\n", mant_base10);
                    printf("exp10 %" PRFExp "\n", exp_base10);
                    printf("base rem digit size : %" PRFExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem : %" PRFMant "\n", fl1_num.GetRemainder());
                    printf("rem digit size : %f\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            float exp_base16_f = exp - fl1_base.BitSizeMantissa();
            exp_base16_f *= (std::log((float)2)/std::log((float)16));

            ExponentType exp_base16 = std::floor(std::abs(exp_base16_f));
            float exp_index_f = std::abs(exp_base16_f);
            exp_index_f -= (float)exp_base16;
            if (exp_base16_f < 0)
            {
                exp_index_f = exp_base16_f + (float)exp_base16;
                exp_base16 *= -1;
            }
            else if(exp_index_f != 0)
            {
                exp_index_f = exp_base16_f - (float)exp_base16;
                exp_index_f -= 1;
                exp_base16 += 1;
            }

            float mant_base16_f = mant;
            mant_base16_f *= std::pow((float)16, exp_index_f);
            MantissaType mant_base16 = std::floor(mant_base16_f);

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {

                if (fl1_num.GetExponent() != exp_base16)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base exp %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base16);

                if (fl1_num.GetInteger() != mant_base16)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant_base16);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                float int_ndigit = 1;
                if (fl1_num.GetInteger() != 0)
                {
                    int_ndigit = std::log((float)fl1_num.GetInteger());
                    int_ndigit /= std::log((float)16);
                    int_ndigit = std::floor(int_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("int : %" PRFMant "\n", fl1_num.GetInteger());
                    printf("base int digit size %" PRFExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %f\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base rem digit size %" PRFExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base exp %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    float int_val_f = mant_base16;
                    int_val_f *= std::pow((float)16, exp_base16);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRFMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    float int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((float)fl1_num.GetInteger());
                        int_ndigit /= std::log((float)16);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("int : %" PRFMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRFExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("base rem digit size %" PRFExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant_base16;
                    int_val *= std::pow((float)16, exp_base16);
                    MantissaType rem_val = (MantissaType)(mant_base16 - 
                        (int_val * (MantissaType)(std::pow((float)16, 
                        -fl1_num.GetExponent()))));

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("base int %" PRFMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRFMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("base rem %" PRFMant "\n", fl1_num.GetRemainder());
                        printf("rem val %" PRFMant "\n", rem_val);
                    }
                    assert(fl1_num.GetRemainder() == rem_val);
                    
                    float int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((float)fl1_num.GetInteger());
                        int_ndigit /= std::log((float)16);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }
                    float rem_ndigit = 1;
                    if (fl1_num.GetRemainder() != 0)
                    {
                        rem_ndigit = std::log((float)fl1_num.GetRemainder());
                        rem_ndigit /= std::log((float)16);
                        rem_ndigit = std::floor(rem_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("int : %" PRFMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRFExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRFMant "\n", mant);
                        printf("exp %" PRFExp "\n", exp);
                        printf("mant16 %" PRFMant "\n", mant_base16);
                        printf("exp16 %" PRFExp "\n", exp_base16);
                        printf("rem : %" PRFMant "\n", fl1_num.GetRemainder());
                        printf("base rem digit size %" PRFExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %f\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base16)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base exp : %" PRFExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base16);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base int : %" PRFMant"\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant_base16)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base rem : %" PRFMant"\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant_base16);
                
                float rem_ndigit = 1;
                if (fl1_num.GetRemainder() != 0)
                {
                    rem_ndigit = std::log((float)fl1_num.GetRemainder());
                    rem_ndigit /= std::log((float)16);
                    rem_ndigit = std::floor(rem_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base int digit size : %" PRFExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRFMant "\n", mant);
                    printf("exp %" PRFExp "\n", exp);
                    printf("mant16 %" PRFMant "\n", mant_base16);
                    printf("exp16 %" PRFExp "\n", exp_base16);
                    printf("base rem digit size : %" PRFExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem : %" PRFMant "\n", fl1_num.GetRemainder());
                    printf("rem digit size : %f\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
    }
    ///
    
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<double>::MinimumExponent()) + MaxDigit<double>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<double>::MaximumExponent()) - 
            MaxDigit<double>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        typedef typename test::FloatingPoint<double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType 
            ExponentType;
        double f1_int = 0.0;
        while(f1_int == 0.0) f1_int = Random<double>();
        double f1 = f1_int * std::pow((double)10, pn);
        test::FloatingPoint<double> fl1{f1};
        auto mant = fl1.GetNormalMantissa();
        auto exp = fl1.GetExponent();

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            auto exp_base2 = exp;
            exp_base2 -= fl1_base.BitSizeMantissa();

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {
                if (fl1_num.GetExponent() != exp_base2)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("exp2 %" PRDExp "\n", exp_base2);
                    printf("base exp %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base2);

                if (fl1_num.GetInteger() != mant)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                double int_ndigit = 
                    test::bit::index::Big(fl1_num.GetInteger());
                int_ndigit = std::floor(int_ndigit) + 1;

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base int digit size %" PRDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %f\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base rem digit size %" PRDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base exp %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    double int_val_f = mant;
                    int_val_f *= std::pow((double)2, exp_base2);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    double int_ndigit = 
                        test::bit::index::Big(fl1_num.GetInteger());
                    int_ndigit += 1;

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base int digit size %" PRDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base rem digit size %" PRDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant;
                    int_val *= std::pow((double)2, exp_base2);

                    double rem_val_f = (f1 - int_val);
                    rem_val_f *= std::pow((double)2, 
                        -fl1_num.GetExponent());
                    rem_val_f = std::round(rem_val_f);

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val_f)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                        printf("rem val %f\n", rem_val_f);
                    }
                    assert(fl1_num.GetRemainder() == rem_val_f);
                    
                    double int_ndigit = 
                        test::bit::index::Big(fl1_num.GetInteger());
                    int_ndigit = std::floor(int_ndigit) + 1;
                    double rem_ndigit = 
                        test::bit::index::Big(fl1_num.GetRemainder());
                    rem_ndigit = std::floor(rem_ndigit) + 1;

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base int digit size %" PRDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("base rem digit size %" PRDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %f\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base2)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("exp2 %" PRDExp "\n", exp_base2);
                    printf("base exp : %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base2);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base int : %" PRDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base rem : %" PRDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant);
                
                double rem_ndigit = 
                    test::bit::index::Big(fl1_num.GetRemainder());
                rem_ndigit = std::floor(rem_ndigit) + 1;

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base int digit size : %" PRDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("base rem digit size : %" PRDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem digit size : %f\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            double exp_base10_f = exp - fl1_base.BitSizeMantissa();
            exp_base10_f *= (std::log((double)2)/std::log((double)10));

            ExponentType exp_base10 = std::floor(std::abs(exp_base10_f));
            double exp_index_f = std::abs(exp_base10_f);
            exp_index_f -= (double)exp_base10;
            if (exp_base10_f < 0)
            {
                exp_index_f = exp_base10_f + (double)exp_base10;
                exp_base10 *= -1;
            }
            else if(exp_index_f != 0)
            {
                exp_index_f = exp_base10_f - (double)exp_base10;
                exp_index_f -= 1;
                exp_base10 += 1;
            }

            double mant_base10_f = mant;
            mant_base10_f *= std::pow((double)10, exp_index_f);
            MantissaType mant_base10 = std::floor(mant_base10_f);

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {

                if (fl1_num.GetExponent() != exp_base10)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base exp %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base10);

                if (fl1_num.GetInteger() != mant_base10)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant_base10);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                double int_ndigit = 1;
                if (fl1_num.GetInteger() != 0)
                {
                    int_ndigit = std::log((double)fl1_num.GetInteger());
                    int_ndigit /= std::log((double)10);
                    int_ndigit = std::floor(int_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("int : %" PRDMant "\n", fl1_num.GetInteger());
                    printf("base int digit size %" PRDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %f\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base rem digit size %" PRDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base exp %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    double int_val_f = mant_base10;
                    int_val_f *= std::pow((double)10, exp_base10);
                    MantissaType int_val = std::round(int_val_f);

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((double)fl1_num.GetInteger());
                        int_ndigit /= std::log((double)10);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("int : %" PRDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("base rem digit size %" PRDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant_base10;
                    int_val *= std::pow((double)10, exp_base10);
                    MantissaType rem_val = (MantissaType)(mant_base10 - 
                        (int_val * (MantissaType)(std::pow((double)10, 
                        -fl1_num.GetExponent()))));

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                        printf("rem val %" PRDMant "\n", rem_val);
                    }
                    assert(fl1_num.GetRemainder() == rem_val);
                    
                    double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((double)fl1_num.GetInteger());
                        int_ndigit /= std::log((double)10);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }
                    double rem_ndigit = 1;
                    if (fl1_num.GetRemainder() != 0)
                    {
                        rem_ndigit = std::log((double)fl1_num.GetRemainder());
                        rem_ndigit /= std::log((double)10);
                        rem_ndigit = std::floor(rem_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("int : %" PRDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant10 %" PRDMant "\n", mant_base10);
                        printf("exp10 %" PRDExp "\n", exp_base10);
                        printf("rem : %" PRDMant "\n", fl1_num.GetRemainder());
                        printf("base rem digit size %" PRDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %f\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base10)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base exp : %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base10);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base int : %" PRDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant_base10)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base rem : %" PRDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant_base10);
                
                double rem_ndigit = 1;
                if (fl1_num.GetRemainder() != 0)
                {
                    rem_ndigit = std::log((double)fl1_num.GetRemainder());
                    rem_ndigit /= std::log((double)10);
                    rem_ndigit = std::floor(rem_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base int digit size : %" PRDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant10 %" PRDMant "\n", mant_base10);
                    printf("exp10 %" PRDExp "\n", exp_base10);
                    printf("base rem digit size : %" PRDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem : %" PRDMant "\n", fl1_num.GetRemainder());
                    printf("rem digit size : %f\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            double exp_base16_f = exp - fl1_base.BitSizeMantissa();
            exp_base16_f *= (std::log((double)2)/std::log((double)16));

            ExponentType exp_base16 = std::floor(std::abs(exp_base16_f));
            double exp_index_f = std::abs(exp_base16_f);
            exp_index_f -= (double)exp_base16;
            if (exp_base16_f < 0)
            {
                exp_index_f = exp_base16_f + (double)exp_base16;
                exp_base16 *= -1;
            }
            else if(exp_index_f != 0)
            {
                exp_index_f = exp_base16_f - (double)exp_base16;
                exp_index_f -= 1;
                exp_base16 += 1;
            }

            double mant_base16_f = mant;
            mant_base16_f *= std::pow((double)16, exp_index_f);
            MantissaType mant_base16 = std::floor(mant_base16_f);

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {

                if (fl1_num.GetExponent() != exp_base16)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base exp %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base16);

                if (fl1_num.GetInteger() != mant_base16)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant_base16);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                double int_ndigit = 1;
                if (fl1_num.GetInteger() != 0)
                {
                    int_ndigit = std::log((double)fl1_num.GetInteger());
                    int_ndigit /= std::log((double)16);
                    int_ndigit = std::floor(int_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("int : %" PRDMant "\n", fl1_num.GetInteger());
                    printf("base int digit size %" PRDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %f\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base rem digit size %" PRDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base exp %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    double int_val_f = mant_base16;
                    int_val_f *= std::pow((double)16, exp_base16);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((double)fl1_num.GetInteger());
                        int_ndigit /= std::log((double)16);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("int : %" PRDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("base rem digit size %" PRDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant_base16;
                    int_val *= std::pow((double)16, exp_base16);
                    MantissaType rem_val = (MantissaType)(mant_base16 - 
                        (int_val * (MantissaType)(std::pow((double)16, 
                        -fl1_num.GetExponent()))));

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("base int %" PRDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("base rem %" PRDMant "\n", fl1_num.GetRemainder());
                        printf("rem val %" PRDMant "\n", rem_val);
                    }
                    assert(fl1_num.GetRemainder() == rem_val);
                    
                    double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((double)fl1_num.GetInteger());
                        int_ndigit /= std::log((double)16);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }
                    double rem_ndigit = 1;
                    if (fl1_num.GetRemainder() != 0)
                    {
                        rem_ndigit = std::log((double)fl1_num.GetRemainder());
                        rem_ndigit /= std::log((double)16);
                        rem_ndigit = std::floor(rem_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("int : %" PRDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %f\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRDMant "\n", mant);
                        printf("exp %" PRDExp "\n", exp);
                        printf("mant16 %" PRDMant "\n", mant_base16);
                        printf("exp16 %" PRDExp "\n", exp_base16);
                        printf("rem : %" PRDMant "\n", fl1_num.GetRemainder());
                        printf("base rem digit size %" PRDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %f\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base16)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base exp : %" PRDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base16);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base int : %" PRDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant_base16)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base rem : %" PRDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant_base16);
                
                double rem_ndigit = 1;
                if (fl1_num.GetRemainder() != 0)
                {
                    rem_ndigit = std::log((double)fl1_num.GetRemainder());
                    rem_ndigit /= std::log((double)16);
                    rem_ndigit = std::floor(rem_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base int digit size : %" PRDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRDMant "\n", mant);
                    printf("exp %" PRDExp "\n", exp);
                    printf("mant16 %" PRDMant "\n", mant_base16);
                    printf("exp16 %" PRDExp "\n", exp_base16);
                    printf("base rem digit size : %" PRDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem : %" PRDMant "\n", fl1_num.GetRemainder());
                    printf("rem digit size : %f\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
    }
    ////

    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<long double>::MinimumExponent()) + 
            MaxDigit<long double>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<long double>::MaximumExponent()) - 
            MaxDigit<long double>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        long double f1_int = 0.0L;
        while(f1_int == 0.0L) f1_int = Random<long double>();
        long double f1 = f1_int * std::pow((long double)10, pn);
        test::FloatingPoint<long double> fl1{f1};
        auto mant = fl1.GetNormalMantissa();
        auto exp = fl1.GetExponent();

        {
            auto fl1_base = fl1.template GetBase<2>();
            auto fl1_num = fl1_base.GetNumber();
            auto exp_base2 = exp;
            exp_base2 -= fl1_base.BitSizeMantissa();

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {
                if (fl1_num.GetExponent() != exp_base2)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("exp2 %" PRLDExp "\n", exp_base2);
                    printf("base exp %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base2);

                if (fl1_num.GetInteger() != mant)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                long double int_ndigit = 
                    test::bit::index::Big(fl1_num.GetInteger());
                int_ndigit = std::floor(int_ndigit) + 1;

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base int digit size %" PRLDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %Lf\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base rem digit size %" PRLDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base exp %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    long double int_val_f = mant;
                    int_val_f *= std::pow((long double)2, exp_base2);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRLDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    long double int_ndigit = 
                        test::bit::index::Big(fl1_num.GetInteger());
                    int_ndigit += 1;

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base int digit size %" PRLDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %Lf\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base rem digit size %" PRLDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant;
                    int_val *= std::pow((long double)2, exp_base2);

                    long double rem_val_f = (f1 - int_val);
                    rem_val_f *= std::pow((long double)2, 
                        -fl1_num.GetExponent());
                    rem_val_f = std::round(rem_val_f);

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRLDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val_f)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                        printf("rem val %Lf\n", rem_val_f);
                    }
                    assert(fl1_num.GetRemainder() == rem_val_f);
                    
                    long double int_ndigit = 
                        test::bit::index::Big(fl1_num.GetInteger());
                    int_ndigit = std::floor(int_ndigit) + 1;
                    long double rem_ndigit = 
                        test::bit::index::Big(fl1_num.GetRemainder());
                    rem_ndigit = std::floor(rem_ndigit) + 1;

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base int digit size %" PRLDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %Lf\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("base rem digit size %" PRLDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %Lf\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base2)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("exp2 %" PRLDExp "\n", exp_base2);
                    printf("base exp : %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base2);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base int : %" PRLDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant);
                
                long double rem_ndigit = 
                    test::bit::index::Big(fl1_num.GetRemainder());
                rem_ndigit = std::floor(rem_ndigit) + 1;

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base int digit size : %" PRLDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("base rem digit size : %" PRLDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem digit size : %Lf\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
        {
            auto fl1_base = fl1.template GetBase<10>();
            auto fl1_num = fl1_base.GetNumber();
            long double exp_base10_f = exp - fl1_base.BitSizeMantissa();
            exp_base10_f *= 
                (std::log((long double)2)/std::log((long double)10));

            ExponentType exp_base10 = std::floor(std::abs(exp_base10_f));
            long double exp_index_f = std::abs(exp_base10_f);
            exp_index_f -= (long double)exp_base10;
            if (exp_base10_f < 0)
            {
                exp_index_f = exp_base10_f + (long double)exp_base10;
                exp_base10 *= -1;
            }
            else if(exp_index_f != 0)
            {
                exp_index_f = exp_base10_f - (long double)exp_base10;
                exp_index_f -= 1;
                exp_base10 += 1;
            }

            long double mant_base10_f = mant;
            mant_base10_f *= std::pow((long double)10, exp_index_f);
            MantissaType mant_base10 = std::floor(mant_base10_f);

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {

                if (fl1_num.GetExponent() != exp_base10)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base exp %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base10);

                if (fl1_num.GetInteger() != mant_base10)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant_base10);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                long double int_ndigit = 1;
                if (fl1_num.GetInteger() != 0)
                {
                    int_ndigit = std::log((long double)fl1_num.GetInteger());
                    int_ndigit /= std::log((long double)10);
                    int_ndigit = std::floor(int_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("int : %" PRLDMant "\n", fl1_num.GetInteger());
                    printf("base int digit size %" PRLDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %Lf\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base rem digit size %" PRLDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base exp %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    long double int_val_f = mant_base10_f;
                    int_val_f *= std::pow((long double)10, exp_base10);
                    MantissaType int_val = std::round(int_val_f);

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRLDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    long double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((long double)fl1_num.GetInteger());
                        int_ndigit /= std::log((long double)10);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("int : %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRLDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %Lf\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("base rem digit size %" PRLDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    long double int_val_f = mant_base10_f;
                    int_val_f *= std::pow((long double)10, exp_base10);
                    MantissaType int_val = std::floor(int_val_f);
                    MantissaType rem_val = (MantissaType)(mant_base10_f - 
                        (int_val * (MantissaType)(std::pow((long double)10, 
                        -fl1_num.GetExponent()))));

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRLDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                        printf("rem val %" PRLDMant "\n", rem_val);
                    }
                    assert(fl1_num.GetRemainder() == rem_val);
                    
                    long double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((long double)fl1_num.GetInteger());
                        int_ndigit /= std::log((long double)10);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }
                    long double rem_ndigit = 1;
                    if (fl1_num.GetRemainder() != 0)
                    {
                        rem_ndigit = std::log((long double)fl1_num.GetRemainder());
                        rem_ndigit /= std::log((long double)10);
                        rem_ndigit = std::floor(rem_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("int : %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRLDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %Lf\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant10 %" PRLDMant "\n", mant_base10);
                        printf("exp10 %" PRLDExp "\n", exp_base10);
                        printf("rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                        printf("base rem digit size %" PRLDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %Lf\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base10)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base exp : %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base10);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base int : %" PRLDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant_base10)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant_base10);
                
                long double rem_ndigit = 1;
                if (fl1_num.GetRemainder() != 0)
                {
                    rem_ndigit = std::log((long double)fl1_num.GetRemainder());
                    rem_ndigit /= std::log((long double)10);
                    rem_ndigit = std::floor(rem_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base int digit size : %" PRLDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant10 %" PRLDMant "\n", mant_base10);
                    printf("exp10 %" PRLDExp "\n", exp_base10);
                    printf("base rem digit size : %" PRLDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                    printf("rem digit size : %Lf\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
        {
            auto fl1_base = fl1.template GetBase<16>();
            auto fl1_num = fl1_base.GetNumber();
            long double exp_base16_f = exp - fl1_base.BitSizeMantissa();
            exp_base16_f *= 
                (std::log((long double)2)/std::log((long double)16));

            ExponentType exp_base16 = std::floor(std::abs(exp_base16_f));
            long double exp_index_f = std::abs(exp_base16_f);
            exp_index_f -= (long double)exp_base16;
            if (exp_base16_f < 0)
            {
                exp_index_f = exp_base16_f + (long double)exp_base16;
                exp_base16 *= -1;
            }
            else if(exp_index_f != 0)
            {
                exp_index_f = exp_base16_f - (long double)exp_base16;
                exp_index_f -= 1;
                exp_base16 += 1;
            }

            long double mant_base16_f = mant;
            mant_base16_f *= std::pow((long double)16, exp_index_f);
            MantissaType mant_base16 = std::floor(mant_base16_f);

            assert(fl1_base.Classify() == FP_NORMAL);
            
            if (exp >= fl1_base.BitSizeMantissa())
            {

                if (fl1_num.GetExponent() != exp_base16)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base exp %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base16);

                if (fl1_num.GetInteger() != mant_base16)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == mant_base16);

                if (fl1_num.GetRemainder() > 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() <= 0);

                long double int_ndigit = 1;
                if (fl1_num.GetInteger() != 0)
                {
                    int_ndigit = std::log((long double)fl1_num.GetInteger());
                    int_ndigit /= std::log((long double)16);
                    int_ndigit = std::floor(int_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("int : %" PRLDMant "\n", fl1_num.GetInteger());
                    printf("base int digit size %" PRLDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                    printf("int digit size %Lf\n", int_ndigit);
                }
                assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                if (fl1_num.GetRemainderDigitSize() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base rem digit size %" PRLDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                }
                assert(fl1_num.GetRemainderDigitSize() == 0);
            }
            else if (exp >= 0)
            {
                if (fl1_num.GetExponent() > 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base exp %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() <= 0);
                if (fl1_num.GetExponent() == 0)
                {
                    long double int_val_f = mant_base16;
                    int_val_f *= std::pow((long double)16, exp_base16);
                    MantissaType int_val = std::round(int_val_f);
                    
                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRLDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);

                    if (fl1_num.GetRemainder() != 0)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                    }
                    assert(fl1_num.GetRemainder() == 0);
                    
                    long double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((long double)fl1_num.GetInteger());
                        int_ndigit /= std::log((long double)16);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("int : %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRLDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %Lf\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);

                    if (fl1_num.GetRemainderDigitSize() != 0)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("base rem digit size %" PRLDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                    }
                    assert(fl1_num.GetRemainderDigitSize() == 0);
                }
                else if (fl1_num.GetExponent() < 0)
                {
                    MantissaType int_val = mant_base16;
                    int_val *= std::pow((long double)16, exp_base16);
                    MantissaType rem_val = (MantissaType)(mant_base16 - 
                        (int_val * (MantissaType)(std::pow((double)16, 
                        -fl1_num.GetExponent()))));

                    if (fl1_num.GetInteger() != int_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("base int %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("int val %" PRLDMant "\n", int_val);
                    }
                    assert(fl1_num.GetInteger() == int_val);
                    
                    if (fl1_num.GetRemainder() != rem_val)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("base rem %" PRLDMant "\n", fl1_num.GetRemainder());
                        printf("rem val %" PRLDMant "\n", rem_val);
                    }
                    assert(fl1_num.GetRemainder() == rem_val);
                    
                    long double int_ndigit = 1;
                    if (fl1_num.GetInteger() != 0)
                    {
                        int_ndigit = std::log((long double)fl1_num.GetInteger());
                        int_ndigit /= std::log((long double)16);
                        int_ndigit = std::floor(int_ndigit) + 1;
                    }
                    long double rem_ndigit = 1;
                    if (fl1_num.GetRemainder() != 0)
                    {
                        rem_ndigit = std::log((long double)fl1_num.GetRemainder());
                        rem_ndigit /= std::log((long double)16);
                        rem_ndigit = std::floor(rem_ndigit) + 1;
                    }

                    if (fl1_num.GetIntegerDigitSize() != int_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("int : %" PRLDMant "\n", fl1_num.GetInteger());
                        printf("base int digit size %" PRLDExp "\n", 
                            fl1_num.GetIntegerDigitSize());
                        printf("int digit size %Lf\n", int_ndigit);
                    }
                    assert(fl1_num.GetIntegerDigitSize() == int_ndigit);
                    
                    if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                    {
                        printf("mant %" PRLDMant "\n", mant);
                        printf("exp %" PRLDExp "\n", exp);
                        printf("mant16 %" PRLDMant "\n", mant_base16);
                        printf("exp16 %" PRLDExp "\n", exp_base16);
                        printf("rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                        printf("base rem digit size %" PRLDExp "\n", 
                            fl1_num.GetRemainderDigitSize());
                        printf("rem digit size %Lf\n", rem_ndigit);
                    }
                    assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);

                }
            }
            else
            {
                if (fl1_num.GetExponent() != exp_base16)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base exp : %" PRLDExp "\n", fl1_num.GetExponent());
                }
                assert(fl1_num.GetExponent() == exp_base16);
                
                if (fl1_num.GetInteger() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base int : %" PRLDMant "\n", fl1_num.GetInteger());
                }
                assert(fl1_num.GetInteger() == 0);
                
                if (fl1_num.GetRemainder() != mant_base16)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                }
                assert(fl1_num.GetRemainder() == mant_base16);
                
                long double rem_ndigit = 1;
                if (fl1_num.GetRemainder() != 0)
                {
                    rem_ndigit = std::log((long double)fl1_num.GetRemainder());
                    rem_ndigit /= std::log((long double)16);
                    rem_ndigit = std::floor(rem_ndigit) + 1;
                }

                if (fl1_num.GetIntegerDigitSize() != 0)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base int digit size : %" PRLDExp "\n", 
                        fl1_num.GetIntegerDigitSize());
                }
                assert(fl1_num.GetIntegerDigitSize() == 0);

                if (fl1_num.GetRemainderDigitSize() != rem_ndigit)
                {
                    printf("mant %" PRLDMant "\n", mant);
                    printf("exp %" PRLDExp "\n", exp);
                    printf("mant16 %" PRLDMant "\n", mant_base16);
                    printf("exp16 %" PRLDExp "\n", exp_base16);
                    printf("base rem digit size : %" PRLDExp "\n", 
                        fl1_num.GetRemainderDigitSize());
                    printf("rem : %" PRLDMant "\n", fl1_num.GetRemainder());
                    printf("rem digit size : %Lf\n", rem_ndigit);
                }
                assert(fl1_num.GetRemainderDigitSize() == rem_ndigit);
            }
        }
    }
    //// SUBNORMAL
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<float>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const float mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<float>::
            MinimumExponent() - (test::FloatingPoint<float>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<float>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<float>::MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            auto fp_num = fp_base.GetNumber();
            float rem_ndigit = test::bit::index::Big(fp_num.GetRemainder());
            rem_ndigit = std::floor(rem_ndigit) + 1;

            assert(fp_num.GetExponent() == exp_base);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == mant_base);
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float exp_b10_f = exp_bin;
            exp_b10_f *=(std::log((float)2)/std::log((float)10));
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (float)exp_b10;
            exp_b10 *= -1;
            float mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((float)10, exp_b10_f);
            
            auto fp_num = fp_base.GetNumber();
            float rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((float)fp_num.GetRemainder());
                rem_ndigit /= std::log((float)10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b10);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b10_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            float exp_b16_f = (std::log((float)2)/std::log((float)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (float)exp_b16;
            exp_b16 *= -1;
            float mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((float)16, exp_b16_f);

            auto fp_num = fp_base.GetNumber();
            float rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((float)fp_num.GetRemainder());
                rem_ndigit /= std::log((float)16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b16);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b16_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<float>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<float>::
            BitFieldMantissa();
        const float mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<float>::
            MinimumExponent() - (test::FloatingPoint<float>::
            BitFieldMantissa() + test::FloatingPoint<float>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<float>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<float>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            auto fp_num = fp_base.GetNumber();
            float rem_ndigit = test::bit::index::Big(fp_num.GetRemainder());
            rem_ndigit = std::floor(rem_ndigit) + 1;

            assert(fp_num.GetExponent() == exp_base);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == mant_base);
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            float exp_b10_f = (std::log((float)2)/std::log((float)10)) * 
                (float)exp_bin;
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (float)exp_b10;
            exp_b10 *= -1;
            float mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((float)10, exp_b10_f);

            auto fp_num = fp_base.GetNumber();
            float rem_ndigit = 1;
            if (fp_num.GetRemainder()) 
            {
                rem_ndigit = std::log((float)fp_num.GetRemainder());
                rem_ndigit /= std::log((float)10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b10);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b10_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            float exp_b16_f = (std::log((float)2)/std::log((float)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (float)exp_b16;
            exp_b16 *= -1;
            float mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((float)16, exp_b16_f);

            auto fp_num = fp_base.GetNumber();
            float rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((float)fp_num.GetRemainder());
                rem_ndigit /= std::log((float)16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b16);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b16_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    {
        typedef typename test::FloatingPoint<double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType 
            ExponentType;
        test::FloatingPoint<double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<double>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<double>::
            MinimumExponent() - (test::FloatingPoint<double>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<double>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<double>::
            MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            auto fp_num = fp_base.GetNumber();
            double rem_ndigit = test::bit::index::Big(fp_num.GetRemainder());
            rem_ndigit = std::floor(rem_ndigit) + 1;

            assert(fp_num.GetExponent() == exp_base);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == mant_base);
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double exp_b10_f = exp_bin;
            exp_b10_f *=(std::log((double)2)/std::log((double)10));
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (double)exp_b10;
            exp_b10 *= -1;
            double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((double)10, exp_b10_f);
            
            auto fp_num = fp_base.GetNumber();
            double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((double)fp_num.GetRemainder());
                rem_ndigit /= std::log((double)10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b10);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b10_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            double exp_b16_f = 
                (std::log((double)2)/std::log((double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (double)exp_b16;
            exp_b16 *= -1;
            double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((double)16, exp_b16_f);

            auto fp_num = fp_base.GetNumber();
            double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((double)fp_num.GetRemainder());
                rem_ndigit /= std::log((double)16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b16);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b16_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    {
        typedef typename test::FloatingPoint<double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType 
            ExponentType;
        test::FloatingPoint<double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<double>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<double>::
            BitFieldMantissa();
        const double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<double>::
            MinimumExponent() - (test::FloatingPoint<double>::
            BitFieldMantissa() + test::FloatingPoint<double>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<double>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<double>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            auto fp_num = fp_base.GetNumber();
            double rem_ndigit = test::bit::index::Big(fp_num.GetRemainder());
            rem_ndigit = std::floor(rem_ndigit) + 1;

            assert(fp_num.GetExponent() == exp_base);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == mant_base);
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            double exp_b10_f = (std::log((double)2)/std::log((double)10)) * 
                (double)exp_bin;
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (double)exp_b10;
            exp_b10 *= -1;
            double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((double)10, exp_b10_f);

            auto fp_num = fp_base.GetNumber();
            double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((double)fp_num.GetRemainder());
                rem_ndigit /= std::log((double)10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b10);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b10_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            double exp_b16_f = 
                (std::log((double)2)/std::log((double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (double)exp_b16;
            exp_b16 *= -1;
            double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((double)16, exp_b16_f);

            auto fp_num = fp_base.GetNumber();
            double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((double)fp_num.GetRemainder());
                rem_ndigit /= std::log((double)16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b16);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b16_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        test::FloatingPoint<long double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<long double>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const long double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<long double>::
            MinimumExponent() - (test::FloatingPoint<long double>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<long double>::
            MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<long double>::
            MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            auto fp_num = fp_base.GetNumber();
            long double rem_ndigit = 
                test::bit::index::Big(fp_num.GetRemainder());
            rem_ndigit = std::floor(rem_ndigit) + 1;

            assert(fp_num.GetExponent() == exp_base);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == mant_base);
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double exp_b10_f = exp_bin;
            exp_b10_f *=(std::log((long double)2)/std::log((long double)10));
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (long double)exp_b10;
            exp_b10 *= -1;
            long double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((long double)10, exp_b10_f);
            
            auto fp_num = fp_base.GetNumber();
            long double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((long double)fp_num.GetRemainder());
                rem_ndigit /= std::log((long double)10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b10);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b10_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            long double exp_b16_f = 
                (std::log((long double)2)/std::log((long double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (long double)exp_b16;
            exp_b16 *= -1;
            long double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((long double)16, exp_b16_f);

            auto fp_num = fp_base.GetNumber();
            long double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((long double)fp_num.GetRemainder());
                rem_ndigit /= std::log((long double)16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b16);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b16_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        test::FloatingPoint<long double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<long double>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<long double>::
            BitFieldMantissa();
        const long double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<long double>::
            MinimumExponent() - (test::FloatingPoint<long double>::
            BitFieldMantissa() + test::FloatingPoint<long double>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<long double>::
            MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<long double>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();

            auto fp_num = fp_base.GetNumber();
            long double rem_ndigit = 
                test::bit::index::Big(fp_num.GetRemainder());
            rem_ndigit = std::floor(rem_ndigit) + 1;

            assert(fp_num.GetExponent() == exp_base);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == mant_base);
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<10>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            long double exp_b10_f = 
                (std::log((long double)2)/std::log((long double)10)) * 
                (long double)exp_bin;
            ExponentType exp_b10 = std::floor(std::abs(exp_b10_f));
            exp_b10_f = exp_b10_f + (long double)exp_b10;
            exp_b10 *= -1;
            long double mant_b10_f = mant_bin_f;
            mant_b10_f *= std::pow((long double)10, exp_b10_f);

            auto fp_num = fp_base.GetNumber();
            long double rem_ndigit = 1;
            if(fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((long double)fp_num.GetRemainder());
                rem_ndigit /= std::log((long double)10);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b10);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b10_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
        {
            auto fp_base = fl1.GetBase<16>();
            auto exp_base = fp_base.GetExponent();
            auto mant_base = fp_base.GetMantissa();
            
            long double exp_b16_f = 
                (std::log((long double)2)/std::log((long double)16)) * exp_bin;
            ExponentType exp_b16 = std::floor(std::abs(exp_b16_f));
            exp_b16_f = exp_b16_f + (long double)exp_b16;
            exp_b16 *= -1;
            long double mant_b16_f = mant_bin_f;
            mant_b16_f *= std::pow((long double)16, exp_b16_f);

            auto fp_num = fp_base.GetNumber();
            long double rem_ndigit = 1;
            if (fp_num.GetRemainder() != 0)
            {
                rem_ndigit = std::log((long double)fp_num.GetRemainder());
                rem_ndigit /= std::log((long double)16);
                rem_ndigit = std::floor(rem_ndigit) + 1;
            }

            assert(fp_num.GetExponent() == exp_b16);
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == std::floor(mant_b16_f));
            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == rem_ndigit);
        }
    }
    ////
    {
        typedef test::FloatingPoint<float>::MantissaType MantissaType;
        float f1 = 0.314f;
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            float rem = 1;
            rem *= std::pow((float)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((float)2, 1);
            rem = std::floor(rem);

            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float rem = fp_num.GetInteger();
            rem *= std::pow((float)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float rem = fp_num.GetInteger();
            rem *= std::pow((float)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 5);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        float f1 = 314.0f;
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            float rem = 1;
            rem *= std::pow((float)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((float)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 8);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float rem = fp_num.GetInteger();
            rem *= std::pow((float)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float rem = fp_num.GetInteger();
            rem *= std::pow((float)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        float f1 = 3.14f;
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            float rem = 1;
            rem *= std::pow((float)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((float)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float rem = fp_num.GetInteger();
            rem *= std::pow((float)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float rem = fp_num.GetInteger();
            rem *= std::pow((float)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        const float f1_int = 0.0f;
        int pn = 0;
        float f1 = f1_int * std::pow(10, pn);
        test::FloatingPoint<float> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);
            
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);

        }
    }
    
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<float>::MinimumExponent()) + MaxDigit<float>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<float>::MaximumExponent()) - 
            MaxDigit<float>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        float f1_int = 0.0f;
        while(f1_int == 0.0f) f1_int = Random<float>();
        float f1 = f1_int * std::pow((float)10, pn);
        test::FloatingPoint<float> fl1{f1};
        auto mant = fl1.GetNormalMantissa();
        auto exp = fl1.GetExponent();

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            float rem = 1;
            rem *= std::pow((float)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((float)2, 1);
            rem = std::floor(rem);

            if (fp_num.GetInteger() != 1)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
            }
            assert(fp_num.GetInteger() == 1);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("num rem %" PRFMant "\n", fp_num.GetRemainder());
                printf("rem %f\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num exp %" PRFExp "\n", fp_num.GetExponent());
                printf("exp %" PRFExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRFExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != mant_size)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRFExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %zd\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float _int = mant;
            _int *= std::pow((float)10, -(mant_size - 1));
            _int = std::floor(_int);
            float rem = _int;
            rem *= std::pow((float)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            if (fp_num.GetInteger() != _int)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("int %f\n", _int);
            }
            assert(fp_num.GetInteger() == _int);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("num rem %" PRFMant "\n", fp_num.GetRemainder());
                printf("rem %f\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("num rem %" PRFMant "\n", fp_num.GetRemainder());
                printf("num exp %" PRFExp "\n", fp_num.GetExponent());
                printf("mant_size %f\n", mant_size);
                printf("exp %" PRFExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRFExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRFExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %f\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.template GetBase<16, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float _int = mant;
            _int *= std::pow((float)16, -(mant_size - 1));
            _int = std::floor(_int);
            float rem = _int;
            rem *= std::pow((float)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            if (fp_num.GetInteger() != _int)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("int %f\n", _int);
            }
            assert(fp_num.GetInteger() == _int);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("num rem %" PRFMant "\n", fp_num.GetRemainder());
                printf("rem %f\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int %" PRFMant "\n", fp_num.GetInteger());
                printf("num rem %" PRFMant "\n", fp_num.GetRemainder());
                printf("num exp %" PRFExp "\n", fp_num.GetExponent());
                printf("mant_size %f\n", mant_size);
                printf("exp %" PRFExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRFExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRFMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRFExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRFExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRFExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %f\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    ///
    {
        typedef test::FloatingPoint<double>::MantissaType MantissaType;
        double f1 = 0.314;
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            double rem = 1;
            rem *= std::pow((double)2, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);

            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double rem = fp_num.GetInteger();
            rem *= std::pow((double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double rem = fp_num.GetInteger();
            rem *= std::pow((double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 5);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        double f1 = 314.0;
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            double rem = 1;
            rem *= std::pow((double)2, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 8);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double rem = fp_num.GetInteger();
            rem *= std::pow((double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double rem = fp_num.GetInteger();
            rem *= std::pow((double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        double f1 = 3.14;
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            double rem = 1;
            rem *= std::pow((double)2, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double rem = fp_num.GetInteger();
            rem *= std::pow((double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double rem = fp_num.GetInteger();
            rem *= std::pow((double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        const double f1_int = 0.0;
        int pn = 0;
        double f1 = f1_int * std::pow(10, pn);
        test::FloatingPoint<double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);
            
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);

        }
    }
    
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<double>::MinimumExponent()) + MaxDigit<double>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<double>::MaximumExponent()) - 
            MaxDigit<double>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        typedef typename test::FloatingPoint<double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType 
            ExponentType;
        double f1_int = 0.0;
        while(f1_int == 0.0) f1_int = Random<double>();
        double f1 = f1_int * std::pow((double)10, pn);
        test::FloatingPoint<double> fl1{f1};
        auto mant = fl1.GetNormalMantissa();
        auto exp = fl1.GetExponent();

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            double rem = 1;
            rem *= std::pow((double)2, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);

            if (fp_num.GetInteger() != 1)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
            }
            assert(fp_num.GetInteger() == 1);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRDMant "\n", fp_num.GetRemainder());
                printf("rem %f\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num exp %" PRDExp "\n", fp_num.GetExponent());
                printf("exp %" PRDExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRDExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRDExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %zd\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double _int = mant;
            _int *= std::pow((double)10, -(mant_size - 1));
            _int = std::floor(_int);
            double rem = _int;
            rem *= std::pow((double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            if (fp_num.GetInteger() != _int)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("int %f\n", _int);
            }
            assert(fp_num.GetInteger() == _int);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRDMant "\n", fp_num.GetRemainder());
                printf("rem %f\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRDMant "\n", fp_num.GetRemainder());
                printf("num exp %" PRDExp "\n", fp_num.GetExponent());
                printf("mant_size %f\n", mant_size);
                printf("exp %" PRDExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRDExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRDExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %f\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.template GetBase<16, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double _int = mant;
            _int *= std::pow((double)16, -(mant_size - 1));
            _int = std::floor(_int);
            double rem = _int;
            rem *= std::pow((double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            if (fp_num.GetInteger() != _int)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("int %f\n", _int);
            }
            assert(fp_num.GetInteger() == _int);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRDMant "\n", fp_num.GetRemainder());
                printf("rem %f\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int %" PRDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRDMant "\n", fp_num.GetRemainder());
                printf("num exp %" PRDExp "\n", fp_num.GetExponent());
                printf("mant_size %f\n", mant_size);
                printf("exp %" PRDExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRDExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRDExp "\n", fl1.GetExponent());
                printf("base mant %f\n", fp_base.GetMantissa());
                printf("base exp %" PRDExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRDExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %f\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    ///
    {
        typedef test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        long double f1 = 0.314L;
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            long double rem = 1;
            rem *= std::pow((long double)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((long double)2, 1);
            rem = std::floor(rem);

            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double rem = fp_num.GetInteger();
            rem *= std::pow((long double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double rem = fp_num.GetInteger();
            rem *= std::pow((long double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 5);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == -1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        long double f1 = 314.0L;
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            long double rem = 1;
            rem *= std::pow((long double)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((long double)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 8);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double rem = fp_num.GetInteger();
            rem *= std::pow((long double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double rem = fp_num.GetInteger();
            rem *= std::pow((long double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 2);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        long double f1 = 3.14L;
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant = fl1.GetNormalMantissa();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            long double rem = 1;
            rem *= std::pow((long double)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((long double)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 1);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double rem = fp_num.GetInteger();
            rem *= std::pow((long double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double rem = fp_num.GetInteger();
            rem *= std::pow((long double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 3);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
            
        }
    }
    {
        const long double f1_int = 0.0L;
        int pn = 0;
        long double f1 = f1_int * std::pow(10, pn);
        test::FloatingPoint<long double> fl1{f1};
        {
            auto fp_base = fl1.GetBase<2, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);
            
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            
            assert(fp_num.GetInteger() == 0);
            assert(fp_num.GetRemainder() == 0);
            assert(fp_num.GetExponent() == 0);

            assert(fp_num.GetIntegerDigitSize() == 0);
            assert(fp_num.GetRemainderDigitSize() == 0);

        }
    }
    
    for(int pn = ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<long double>::MinimumExponent()) + 
        MaxDigit<long double>()); 
        pn <= ((int)std::floor(std::log10(2) * 
        test::FloatingPoint<long double>::MaximumExponent()) - 
            MaxDigit<long double>()); ++pn)
    for(int i = 0; i < 100; ++i)
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        long double f1_int = 0.0L;
        while(f1_int == 0.0L) f1_int = Random<long double>();
        long double f1 = f1_int * std::pow((long double)10, pn);
        test::FloatingPoint<long double> fl1{f1};
        auto mant = fl1.GetNormalMantissa();
        auto exp = fl1.GetExponent();

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant);
            mant_size += 1;
            long double rem = 1;
            rem *= std::pow((long double)2, mant_size - 1);
            rem = mant - rem;
            rem *= std::pow((long double)2, 1);
            rem = std::floor(rem);

            if (fp_num.GetInteger() != 1)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
            }
            assert(fp_num.GetInteger() == 1);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRLDMant "\n", fp_num.GetRemainder());
                printf("rem %Lf\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num exp %" PRLDExp "\n", fp_num.GetExponent());
                printf("exp %" PRLDExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRLDExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != mant_size)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRLDExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %zd\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double _int = mant;
            _int *= std::pow((long double)10, -(mant_size - 1));
            _int = std::floor(_int);
            long double rem = _int;
            rem *= std::pow((long double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            if (fp_num.GetInteger() != _int)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("int %Lf\n", _int);
            }
            assert(fp_num.GetInteger() == _int);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRLDMant "\n", fp_num.GetRemainder());
                printf("rem %Lf\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRLDMant "\n", fp_num.GetRemainder());
                printf("num exp %" PRLDExp "\n", fp_num.GetExponent());
                printf("mant_size %Lf\n", mant_size);
                printf("exp %" PRLDExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRLDExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRLDExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %Lf\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.template GetBase<16, true>();
            
            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double _int = mant;
            _int *= std::pow((long double)16, -(mant_size - 1));
            _int = std::floor(_int);
            long double rem = _int;
            rem *= std::pow((long double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            if (fp_num.GetInteger() != _int)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("int %Lf\n", _int);
            }
            assert(fp_num.GetInteger() == _int);

            if (fp_num.GetRemainder() != rem)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRLDMant "\n", fp_num.GetRemainder());
                printf("rem %Lf\n", rem);
            }
            assert(fp_num.GetRemainder() == rem);

            if (fp_num.GetExponent() != exp)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int %" PRLDMant "\n", fp_num.GetInteger());
                printf("num rem %" PRLDMant "\n", fp_num.GetRemainder());
                printf("num exp %" PRLDExp "\n", fp_num.GetExponent());
                printf("mant_size %Lf\n", mant_size);
                printf("exp %" PRLDExp "\n", exp);
            }
            assert(fp_num.GetExponent() == exp);

            if (fp_num.GetIntegerDigitSize() != 1)
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num int digit size %" PRLDExp "\n", 
                    fp_num.GetIntegerDigitSize());
            }
            assert(fp_num.GetIntegerDigitSize() == 1);

            if (fp_num.GetRemainderDigitSize() != (mant_size - 1))
            {
                printf("mant %" PRLDMant "\n", fl1.GetNormalMantissa());
                printf("exp %" PRLDExp "\n", fl1.GetExponent());
                printf("base mant %Lf\n", fp_base.GetMantissa());
                printf("base exp %" PRLDExp "\n", fp_base.GetExponent());
                printf("num rem digit size %" PRLDExp "\n", 
                    fp_num.GetRemainderDigitSize());
                printf("mant_size %Lf\n", mant_size);
            }
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    /// SUBNORMAL
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<float>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const float mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<float>::
            MinimumExponent() - (test::FloatingPoint<float>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<float>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<float>::MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant_bin_int);
            mant_size += 1;
            float rem = 1;
            rem *= std::pow((float)2, mant_size - 1);
            rem = mant_bin_int - rem;
            rem *= std::pow((float)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == fl1.GetExponent());

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float _int = mant;
            _int *= std::pow((float)10, -(mant_size - 1));
            _int = std::floor(_int);
            float rem = _int;
            rem *= std::pow((float)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));

        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float _int = mant;
            _int *= std::pow((float)16, -(mant_size - 1));
            _int = std::floor(_int);
            float rem = _int;
            rem *= std::pow((float)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    {
        typedef typename test::FloatingPoint<float>::MantissaType MantissaType;
        typedef typename test::FloatingPoint<float>::ExponentType ExponentType;
        test::FloatingPoint<float> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<float>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<float>::
            BitFieldMantissa();
        const float mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<float>::
            MinimumExponent() - (test::FloatingPoint<float>::
            BitFieldMantissa() + test::FloatingPoint<float>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<float>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<float>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant_bin_int);
            mant_size += 1;
            float rem = 1;
            rem *= std::pow((float)2, mant_size - 1);
            rem = mant_bin_int - rem;
            rem *= std::pow((float)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == (exp_bin + 
                test::FloatingPoint<float>::BitFieldMantissa()));

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float _int = mant;
            _int *= std::pow((float)10, -(mant_size - 1));
            _int = std::floor(_int);
            float rem = _int;
            rem *= std::pow((float)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;
            
            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((float)mant);
            mant_size /= std::log((float)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            float _int = mant;
            _int *= std::pow((float)16, -(mant_size - 1));
            _int = std::floor(_int);
            float rem = _int;
            rem *= std::pow((float)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    ///
    {
        typedef typename test::FloatingPoint<double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType 
            ExponentType;
        test::FloatingPoint<double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<double>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<double>::
            MinimumExponent() - (test::FloatingPoint<double>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<double>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<double>::MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant_bin_int);
            mant_size += 1;
            double rem = 1;
            rem *= std::pow((double)2, mant_size - 1);
            rem = mant_bin_int - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == fl1.GetExponent());

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double _int = mant;
            _int *= std::pow((double)10, -(mant_size - 1));
            _int = std::floor(_int);
            double rem = _int;
            rem *= std::pow((double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));

        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double _int = mant;
            _int *= std::pow((double)16, -(mant_size - 1));
            _int = std::floor(_int);
            double rem = _int;
            rem *= std::pow((double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    {
        typedef typename test::FloatingPoint<double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<double>::ExponentType 
            ExponentType;
        test::FloatingPoint<double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<double>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<double>::
            BitFieldMantissa();
        const double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<double>::
            MinimumExponent() - (test::FloatingPoint<double>::
            BitFieldMantissa() + test::FloatingPoint<double>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<double>::MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<double>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant_bin_int);
            mant_size += 1;
            double rem = 1;
            rem *= std::pow((double)2, mant_size - 1);
            rem = mant_bin_int - rem;
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == (exp_bin + 
                test::FloatingPoint<double>::BitFieldMantissa()));

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double _int = mant;
            _int *= std::pow((double)10, -(mant_size - 1));
            _int = std::floor(_int);
            double rem = _int;
            rem *= std::pow((double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;
            
            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((double)mant);
            mant_size /= std::log((double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            double _int = mant;
            _int *= std::pow((double)16, -(mant_size - 1));
            _int = std::floor(_int);
            double rem = _int;
            rem *= std::pow((double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    ///
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        test::FloatingPoint<long double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<long double>::
            MaximumSubNormalMantissa();
        mant_bin_int <<= 1;
        const long double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<long double>::
            MinimumExponent() - (test::FloatingPoint<long double>::
            BitFieldMantissa() + 1);
        fl1.SetExponent(test::FloatingPoint<long double>::
            MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<long double>::
            MaximumSubNormalMantissa());
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant_bin_int);
            mant_size += 1;
            long double rem = 1;
            rem *= std::pow((long double)2, mant_size - 1);
            rem = mant_bin_int - rem;
            rem *= std::pow((long double)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == fl1.GetExponent());

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double _int = mant;
            _int *= std::pow((long double)10, -(mant_size - 1));
            _int = std::floor(_int);
            long double rem = _int;
            rem *= std::pow((long double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));

        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double _int = mant;
            _int *= std::pow((long double)16, -(mant_size - 1));
            _int = std::floor(_int);
            long double rem = _int;
            rem *= std::pow((long double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    {
        typedef typename test::FloatingPoint<long double>::MantissaType 
            MantissaType;
        typedef typename test::FloatingPoint<long double>::ExponentType 
            ExponentType;
        test::FloatingPoint<long double> fl1;
        MantissaType mant_bin_int = test::FloatingPoint<long double>::
            MinimumSubNormalMantissa() + 1;
        mant_bin_int <<= test::FloatingPoint<long double>::
            BitFieldMantissa();
        const long double mant_bin_f = mant_bin_int;
        const ExponentType exp_bin = test::FloatingPoint<long double>::
            MinimumExponent() - (test::FloatingPoint<long double>::
            BitFieldMantissa() + test::FloatingPoint<long double>::
            BitFieldMantissa());
        fl1.SetExponent(test::FloatingPoint<long double>::
            MinimumExponent() - 1);
        fl1.SetMantissa(test::FloatingPoint<long double>::
            MinimumSubNormalMantissa() + 1);
        assert(std::fpclassify(fl1.GetFloat()) == FP_SUBNORMAL);

        {
            auto fp_base = fl1.GetBase<2, true>();
            auto fp_num = fp_base.GetNumber();
            auto mant_size = test::bit::index::Big(mant_bin_int);
            mant_size += 1;
            long double rem = 1;
            rem *= std::pow((long double)2, mant_size - 1);
            rem = mant_bin_int - rem;
            rem *= std::pow((long double)2, 1);
            rem = std::floor(rem);
            
            assert(fp_num.GetInteger() == 1);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == (exp_bin + 
                test::FloatingPoint<long double>::BitFieldMantissa()));

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == mant_size);
        }
        {
            auto fp_base = fl1.GetBase<10, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)10);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double _int = mant;
            _int *= std::pow((long double)10, -(mant_size - 1));
            _int = std::floor(_int);
            long double rem = _int;
            rem *= std::pow((long double)10, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;
            
            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
        {
            auto fp_base = fl1.GetBase<16, true>();

            auto fp_num = fp_base.GetNumber();
            auto mant = fp_base.GetMantissa();
            auto exp = fp_base.GetExponent();
            auto mant_size = std::log((long double)mant);
            mant_size /= std::log((long double)16);
            mant_size = std::floor(mant_size);
            mant_size += 1;
            long double _int = mant;
            _int *= std::pow((long double)16, -(mant_size - 1));
            _int = std::floor(_int);
            long double rem = _int;
            rem *= std::pow((long double)16, mant_size - 1);
            rem = mant - rem;
            rem = std::floor(rem);
            exp += mant_size;
            exp -= 1;

            assert(fp_num.GetInteger() == _int);
            assert(fp_num.GetRemainder() == rem);
            assert(fp_num.GetExponent() == exp);

            assert(fp_num.GetIntegerDigitSize() == 1);
            assert(fp_num.GetRemainderDigitSize() == (mant_size - 1));
        }
    }
    return 0;
}
