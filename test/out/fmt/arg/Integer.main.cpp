#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Integer.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

int main()
{
    {
        test::out::fmt::arg::Integer<signed char> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
            
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        signed char val1 = 4;
        test::out::fmt::arg::Integer<signed char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const signed char val1 = 4;
        test::out::fmt::arg::Integer<signed char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            test::out::fmt::flag::Value<signed char>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        signed char val1 = 4;
        test::out::fmt::arg::Integer<signed char> arg1{
            test::out::fmt::flag::Value<signed char&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const signed char val1 = 4;
        test::out::fmt::arg::Integer<signed char> arg1{
            test::out::fmt::flag::Value<const signed char&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<signed char> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::Integer<short> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
            
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        short val1 = 4;
        test::out::fmt::arg::Integer<short> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const short val1 = 4;
        test::out::fmt::arg::Integer<short> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            test::out::fmt::flag::Value<short>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        short val1 = 4;
        test::out::fmt::arg::Integer<short> arg1{
            test::out::fmt::flag::Value<short&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const short val1 = 4;
        test::out::fmt::arg::Integer<short> arg1{
            test::out::fmt::flag::Value<const short&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<short> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<short> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::Integer<int> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
            
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        int val1 = 4;
        test::out::fmt::arg::Integer<int> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int val1 = 4;
        test::out::fmt::arg::Integer<int> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            test::out::fmt::flag::Value<int>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        int val1 = 4;
        test::out::fmt::arg::Integer<int> arg1{
            test::out::fmt::flag::Value<int&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int val1 = 4;
        test::out::fmt::arg::Integer<int> arg1{
            test::out::fmt::flag::Value<const int&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<int> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<int> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::Integer<long> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
            
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        long val1 = 4;
        test::out::fmt::arg::Integer<long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const long val1 = 4;
        test::out::fmt::arg::Integer<long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            test::out::fmt::flag::Value<long>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        long val1 = 4;
        test::out::fmt::arg::Integer<long> arg1{
            test::out::fmt::flag::Value<long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const long val1 = 4;
        test::out::fmt::arg::Integer<long> arg1{
            test::out::fmt::flag::Value<const long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<long> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    
    {
        test::out::fmt::arg::Integer<long long> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
            
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        long long val1 = 4;
        test::out::fmt::arg::Integer<long long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const long long val1 = 4;
        test::out::fmt::arg::Integer<long long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            test::out::fmt::flag::Value<long long>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        long long val1 = 4;
        test::out::fmt::arg::Integer<long long> arg1{
            test::out::fmt::flag::Value<long long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const long long val1 = 4;
        test::out::fmt::arg::Integer<long long> arg1{
            test::out::fmt::flag::Value<const long long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetLength() == 20);

        constexpr auto fmt = test::out::print::Integer::p_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<long long> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<long long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == true);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_signed));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_ds_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
            
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned char val1 = 4;
        test::out::fmt::arg::Integer<unsigned char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned char val1 = 4;
        test::out::fmt::arg::Integer<unsigned char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            test::out::fmt::flag::Value<unsigned char>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned char val1 = 4;
        test::out::fmt::arg::Integer<unsigned char> arg1{
            test::out::fmt::flag::Value<unsigned char&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned char val1 = 4;
        test::out::fmt::arg::Integer<unsigned char> arg1{
            test::out::fmt::flag::Value<const unsigned char&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned char> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_char |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::Integer<unsigned short> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
            
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned short val1 = 4;
        test::out::fmt::arg::Integer<unsigned short> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned short val1 = 4;
        test::out::fmt::arg::Integer<unsigned short> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            test::out::fmt::flag::Value<unsigned short>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned short val1 = 4;
        test::out::fmt::arg::Integer<unsigned short> arg1{
            test::out::fmt::flag::Value<unsigned short&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned short val1 = 4;
        test::out::fmt::arg::Integer<unsigned short> arg1{
            test::out::fmt::flag::Value<const unsigned short&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned short> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_short |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_short_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::Integer<unsigned int> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
            
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned int val1 = 4;
        test::out::fmt::arg::Integer<unsigned int> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned int val1 = 4;
        test::out::fmt::arg::Integer<unsigned int> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            test::out::fmt::flag::Value<unsigned int>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned int val1 = 4;
        test::out::fmt::arg::Integer<unsigned int> arg1{
            test::out::fmt::flag::Value<unsigned int&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned int val1 = 4;
        test::out::fmt::arg::Integer<unsigned int> arg1{
            test::out::fmt::flag::Value<const unsigned int&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned int> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_int_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::Integer<unsigned long> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
            
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            test::out::fmt::flag::Value<unsigned long>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long> arg1{
            test::out::fmt::flag::Value<unsigned long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long> arg1{
            test::out::fmt::flag::Value<const unsigned long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
            
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{4};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned long long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned long long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long long> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            test::out::fmt::flag::Value<unsigned long long>(4)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        unsigned long long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            test::out::fmt::flag::Value<unsigned long long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const unsigned long long val1 = 4;
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            test::out::fmt::flag::Value<const unsigned long long&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        
        constexpr auto fmt = test::out::print::Integer::du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            4,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Integer::w_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            4,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            4,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Integer::p_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Integer<unsigned long long> arg1{
            4,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierInteger() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == true);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_long_long |
            arg1.GetFlag().define_unsigned));
        assert(arg1.GetValue() == 4);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Integer::wp_du_u_long_long_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Integer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    return 0;
}
