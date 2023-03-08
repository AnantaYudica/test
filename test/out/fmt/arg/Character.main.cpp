#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Character.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

int main()
{
    {
        test::out::fmt::arg::Character<char> arg1{};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);

        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{'a'};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        char val1 = 'a';
        test::out::fmt::arg::Character<char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        const char val1 = 'a';
        test::out::fmt::arg::Character<char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            test::out::fmt::flag::Value<char>('a')
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        char val1 = 'a';
        test::out::fmt::arg::Character<char> arg1{
            test::out::fmt::flag::Value<char&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        const char val1 = 'a';
        test::out::fmt::arg::Character<char> arg1{
            test::out::fmt::flag::Value<const char&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Character::w_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Character::w_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Character::char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);

        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Character::w_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_char);
        assert(arg1.GetValue() == 'a');
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Character::w_char_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{L'a'};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        wchar_t val1 = L'a';
        test::out::fmt::arg::Character<wchar_t> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        const wchar_t val1 = L'a';
        test::out::fmt::arg::Character<wchar_t> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            test::out::fmt::flag::Value<wchar_t>(L'a')
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        wchar_t val1 = L'a';
        test::out::fmt::arg::Character<wchar_t> arg1{
            test::out::fmt::flag::Value<wchar_t&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        const wchar_t val1 = L'a';
        test::out::fmt::arg::Character<wchar_t> arg1{
            test::out::fmt::flag::Value<const wchar_t&>(val1)
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Character::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Character::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Character::wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Character::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{40}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == true);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetFlag().GetDefine() == arg1.GetFlag().define_wchar);
        assert(arg1.GetValue() == L'a');
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 40);
        
        constexpr auto fmt = test::out::print::Character::w_wchar_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Character<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
            
    }
    return 0;
}
