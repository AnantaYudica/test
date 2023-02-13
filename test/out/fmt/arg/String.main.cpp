#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/String.h"

#include <cassert>

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
    }

    {
        test::out::fmt::arg::String<wchar_t*> arg1;
        
        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
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
    }
    {
        test::out::fmt::arg::String<wchar_t*> arg1{
            test::out::fmt::flag::Width{20},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierString() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetPrecision() == 20);
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
    }
    return 0;
}
