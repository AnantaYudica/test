#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Boolean.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

int main()
{
    {
        test::out::fmt::arg::Boolean arg1{};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);

        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);

    }
    {
        test::out::fmt::arg::Boolean arg1{true};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);

        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        bool val1 = true;
        test::out::fmt::arg::Boolean arg1{val1};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);

        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const bool val1 = true;
        test::out::fmt::arg::Boolean arg1{val1};

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Boolean::w_bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Boolean::w_bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
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
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Boolean::bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Boolean::w_bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Boolean arg1{
            true,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierBoolean() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_bool);
        assert(arg1.GetValue() == true);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Boolean::w_bool_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Boolean<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    return 0;
}
