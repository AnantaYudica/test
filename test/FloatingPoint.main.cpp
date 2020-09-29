#include "test/FloatingPoint.h"

#include <cassert>


int main()
{
    {
        test::FloatingPoint<float> fl;
        assert(fl.IsSign() == false);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetSign(true);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetExponent(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == 0);
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetExponent(fl.GetMinimumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetExponent(fl.GetMaximumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetMantissa(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == (fl.GetMinimumNormalMantissa() | 0));
        assert(fl.GetSubNormalMantissa() == 0);
        
        fl.SetMantissa(fl.GetMinimumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMaximumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMaximumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMinimumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMaximumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMaximumSubNormalMantissa());
    }
    {
        typedef test::FloatingPoint<float>::MantissaType MantissaType;
        test::FloatingPoint<float> fl1(3.14f);
        assert(fl1.GetFloat() == 3.14f);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        MantissaType mant_byte1 = 3.14f;
        mant_byte1 &= fl1.GetMaximumSubNormalMantissa();
        assert(fl1.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);
        
        
        test::FloatingPoint<float> fl2(-3.14f);
        assert(fl2.GetFloat() == -3.14f);
        assert(fl2.IsSign() == true);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        assert(fl2.GetNormalMantissa() == (fl2.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
        assert(fl2.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
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

        MantissaType mant_byte1 = 314.0f;
        mant_byte1 &= fl1.GetMaximumSubNormalMantissa();

        assert(fl1.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);

        test::FloatingPoint<float> fl2{(IntegerType)-314};
        assert(fl2.GetFloat() == -314.0f);
        assert(fl2.IsSign() == true);
        assert(fl2.GetExponent() == floor(log2(314)));
        assert(fl2.GetNormalMantissa() == (fl2.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        test::FloatingPoint<double> fl;
        assert(fl.IsSign() == false);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetSign(true);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetExponent(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == 0);
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetExponent(fl.GetMinimumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetExponent(fl.GetMaximumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetMantissa(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == (fl.GetMinimumNormalMantissa() | 0));
        assert(fl.GetSubNormalMantissa() == 0);
        
        fl.SetMantissa(fl.GetMinimumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMaximumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMaximumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMinimumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMaximumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMaximumSubNormalMantissa());
    }
    {
        typedef test::FloatingPoint<double>::MantissaType MantissaType;
        test::FloatingPoint<double> fl1(3.14);
        assert(fl1.GetFloat() == 3.14);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        MantissaType mant_byte1 = 3.14;
        mant_byte1 &= fl1.GetMaximumSubNormalMantissa();
        assert(fl1.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);
        
        
        test::FloatingPoint<double> fl2(-3.14);
        assert(fl2.GetFloat() == -3.14);
        assert(fl2.IsSign() == true);
        assert(fl1.GetExponent() == floor(log2(3.14)));
        assert(fl2.GetNormalMantissa() == (fl2.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
        assert(fl2.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
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

        MantissaType mant_byte1 = 314.0;
        mant_byte1 &= fl1.GetMaximumSubNormalMantissa();

        assert(fl1.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);

        test::FloatingPoint<double> fl2{(IntegerType)-314};
        assert(fl2.GetFloat() == -314.0);
        assert(fl2.IsSign() == true);
        assert(fl2.GetExponent() == floor(log2(314)));
        assert(fl2.GetNormalMantissa() == (fl2.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    {
        test::FloatingPoint<long double> fl;
        assert(fl.IsSign() == false);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetSign(true);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetExponent(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == 0);
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetExponent(fl.GetMinimumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMinimumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetExponent(fl.GetMaximumExponent());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());

        fl.SetMantissa(0);
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == (fl.GetMinimumNormalMantissa() | 0));
        assert(fl.GetSubNormalMantissa() == 0);
        
        fl.SetMantissa(fl.GetMinimumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMaximumNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMaximumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMinimumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMinimumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMinimumSubNormalMantissa());
        
        fl.SetMantissa(fl.GetMaximumSubNormalMantissa());
        assert(fl.IsSign() == true);
        assert(fl.GetExponent() == fl.GetMaximumExponent());
        assert(fl.GetNormalMantissa() == fl.GetMaximumNormalMantissa());
        assert(fl.GetSubNormalMantissa() == fl.GetMaximumSubNormalMantissa());
    }
    {
        typedef test::FloatingPoint<long double>::MantissaType MantissaType;
        test::FloatingPoint<long double> fl1(3.14L);
        assert(fl1.GetFloat() == 3.14L);
        assert(fl1.IsSign() == false);
        assert(fl1.GetExponent() == floor(log2(3.14L)));
        MantissaType mant_byte1 = 3.14L;
        mant_byte1 &= fl1.GetMaximumSubNormalMantissa();
        assert(fl1.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);
        
        
        test::FloatingPoint<long double> fl2(-3.14L);
        assert(fl2.GetFloat() == -3.14L);
        assert(fl2.IsSign() == true);
        assert(fl1.GetExponent() == floor(log2(3.14L)));
        assert(fl2.GetNormalMantissa() == (fl2.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
        assert(fl2.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
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

        MantissaType mant_byte1 = 314.0L;
        mant_byte1 &= fl1.GetMaximumSubNormalMantissa();

        assert(fl1.GetNormalMantissa() == (fl1.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl1.GetSubNormalMantissa() == mant_byte1);

        test::FloatingPoint<long double> fl2{(IntegerType)-314};
        assert(fl2.GetFloat() == -314.0L);
        assert(fl2.IsSign() == true);
        assert(fl2.GetExponent() == floor(log2(314)));
        assert(fl2.GetNormalMantissa() == (fl2.GetMinimumNormalMantissa() |
            mant_byte1));
        assert(fl2.GetSubNormalMantissa() == mant_byte1);
    }
    return 0;
}
