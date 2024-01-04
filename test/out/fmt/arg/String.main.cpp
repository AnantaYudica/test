#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/String.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

int main()
{
    {
        test::out::fmt::arg::String<char*> arg1;
        
        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        
        constexpr auto fmt = test::out::print::String::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<char*> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::String::w_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<char*> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::String::l_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<char*> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::String::l_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<char*> arg1{
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::String::wl_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const char *str1 = "test";
        test::out::fmt::arg::String<char*> arg1{str1};

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
        
        constexpr auto fmt = test::out::print::String::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const char *str1 = "test";
        test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
        
        constexpr auto fmt = test::out::print::String::w_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const char *str1 = "test";
        test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const char *str1 = "test";
        test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const char *str1 = "test";
        test::out::fmt::arg::String<char*> arg1{str1,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }

    {
        test::out::fmt::arg::String<wchar_t*> arg1;
        
        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        
        constexpr auto fmt = test::out::print::String::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<wchar_t*> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::String::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<wchar_t*> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::String::l_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<wchar_t*> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::String::l_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::String<wchar_t*> arg1{
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::String::wl_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    

    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1};

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1};

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::l_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        const wchar_t *str1 = L"test";
        test::out::fmt::arg::String<wchar_t*> arg1{str1,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
        
        constexpr auto fmt = test::out::print::String::wl_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::String<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::String<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    return 0;
}
