#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Boolean.h"

#include <cassert>

int main()
{
    {
        test::out::fmt::arg::Boolean arg1{};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Boolean arg1{true};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        bool val1 = true;
        test::out::fmt::arg::Boolean arg1{val1};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const bool val1 = true;
        test::out::fmt::arg::Boolean arg1{val1};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            test::out::fmt::flag::Value<bool>(true)
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        bool val1 = true;
        test::out::fmt::arg::Boolean arg1{
            test::out::fmt::flag::Value<bool&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const bool val1 = true;
        test::out::fmt::arg::Boolean arg1{
            test::out::fmt::flag::Value<const bool&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    return 0;
}
