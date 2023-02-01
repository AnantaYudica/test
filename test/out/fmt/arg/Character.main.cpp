#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Character.h"

#include <cassert>

int main()
{
    {
        test::out::fmt::arg::Character<char> arg1{};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Character<char> arg1{'a'};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        char val1 = 'a';
        test::out::fmt::arg::Character<char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const char val1 = 'a';
        test::out::fmt::arg::Character<char> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
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
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Character<char> arg1{
            'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{L'a'};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        wchar_t val1 = L'a';
        test::out::fmt::arg::Character<wchar_t> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
    }
    {
        const wchar_t val1 = L'a';
        test::out::fmt::arg::Character<wchar_t> arg1{val1};

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
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
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    {
        test::out::fmt::arg::Character<wchar_t> arg1{
            L'a',
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierCharacter() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
    }
    return 0;
}
