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
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{3.14f};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        float val1 = 3.14f;
        test::out::fmt::arg::FloatingPoint<float> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const float val1 = 3.14f;
        test::out::fmt::arg::FloatingPoint<float> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
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
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::FloatingPoint<float> arg1{
            3.14f,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }

    {
        test::out::fmt::arg::FloatingPoint<double> arg1{};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{3.14};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        double val1 = 3.14;
        test::out::fmt::arg::FloatingPoint<double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const double val1 = 3.14;
        test::out::fmt::arg::FloatingPoint<double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
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
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::FloatingPoint<double> arg1{
            3.14,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }

    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{3.14L};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        long double val1 = 3.14L;
        test::out::fmt::arg::FloatingPoint<long double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const long double val1 = 3.14L;
        test::out::fmt::arg::FloatingPoint<long double> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
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
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::FloatingPoint<long double> arg1{
            3.14L,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierFloatingPoint() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    return 0;
}
