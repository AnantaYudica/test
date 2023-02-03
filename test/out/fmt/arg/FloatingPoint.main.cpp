#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/FloatingPoint.h"

#include <cassert>

int main()
{
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{3.14f};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
    }
    {
        float val1 = 3.14f;
        test::out::fmt::arg::FloatingPoint<float> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
    }
    {
        const float val1 = 3.14f;
        test::out::fmt::arg::FloatingPoint<float> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            test::out::fmt::flag::Value<float>(3.14f)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
    }
    {
        float val1 = 3.14f;
        test::out::fmt::arg::FloatingPoint<float> arg1{
            test::out::fmt::flag::Value<float&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
    }
    {
        const float val1 = 3.14f;
        test::out::fmt::arg::FloatingPoint<float> arg1{
            test::out::fmt::flag::Value<const float&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetPrecision() == 20);
    }
    
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
        assert(arg1.GetPrecision() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_float);
        assert(arg1.GetValue() == 3.14f);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
    }

    {
        test::out::fmt::arg::FloatingPoint<double> arg1{};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{3.14};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
    }
    {
        double val1 = 3.14;
        test::out::fmt::arg::FloatingPoint<double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
    }
    {
        const double val1 = 3.14;
        test::out::fmt::arg::FloatingPoint<double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            test::out::fmt::flag::Value<double>(3.14)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
    }
    {
        double val1 = 3.14;
        test::out::fmt::arg::FloatingPoint<double> arg1{
            test::out::fmt::flag::Value<double&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
    }
    {
        const double val1 = 3.14;
        test::out::fmt::arg::FloatingPoint<double> arg1{
            test::out::fmt::flag::Value<const double&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetPrecision() == 20);
    }
    
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
        assert(arg1.GetPrecision() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_double);
        assert(arg1.GetValue() == 3.14);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
    }

    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{3.14L};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
    }
    {
        long double val1 = 3.14L;
        test::out::fmt::arg::FloatingPoint<long double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
    }
    {
        const long double val1 = 3.14L;
        test::out::fmt::arg::FloatingPoint<long double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            test::out::fmt::flag::Value<long double>(3.14L)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
    }
    {
        long double val1 = 3.14L;
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            test::out::fmt::flag::Value<long double&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
    }
    {
        const long double val1 = 3.14L;
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            test::out::fmt::flag::Value<const long double&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetPrecision() == 20);
    }
    
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
        assert(arg1.GetPrecision() == 20);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == 
            arg1.GetFlag().define_long_double);
        assert(arg1.GetValue() == 3.14L);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
    }
    return 0;
}
