#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Pointer.h"

#include <cassert>

template<typename TChar>
using FormatOutputFuncType = test::out::fmt::Definition::
    FormatOutputFuncType<TChar>;

int main()
{
    {
        test::out::fmt::arg::Pointer<void*> arg1;
        
        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        
        constexpr auto fmt = test::out::print::Pointer::ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        
        constexpr auto fmt = test::out::print::Pointer::w_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        
        constexpr auto fmt = test::out::print::Pointer::wl_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    

    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a};

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::w_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::wl_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a};

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::w_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<int*> arg1{&a,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::l_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{40}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetLength() == 40);
        assert(arg1.GetValue() == &a);
        
        constexpr auto fmt = test::out::print::Pointer::wl_ptr_fmt;
        FormatOutputFuncType<char> fmt_char_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        FormatOutputFuncType<wchar_t> fmt_wchar_fun = 
            &test::out::print::imp::Pointer<fmt>::Output;
        assert(arg1.GetFormatOutput().template Get<char>() == fmt_char_fun);
        assert(arg1.GetFormatOutput().template Get<wchar_t>() == 
            fmt_wchar_fun);
    }
    return 0;
}
