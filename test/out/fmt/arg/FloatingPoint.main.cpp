#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/FloatingPoint.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::w_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::w_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::wp_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::wp_ldf_float_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::w_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::w_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::p_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            wp_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            wp_ldf_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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

        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            w_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            p_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            p_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            w_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            p_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            p_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            wp_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        constexpr auto fmt = test::out::print::FloatingPoint::
            wp_ldf_long_double_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::FloatingPoint<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    return 0;
}
