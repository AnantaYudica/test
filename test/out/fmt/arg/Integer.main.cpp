#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Integer.h"

#include <cassert>

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
    }

    return 0;
}
