#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/Argument.h"

#include <cassert>

struct Obj
{
    int val;
    Obj() : val(0) {}
    Obj(int v) : val(v) {}
    Obj(const Obj& o) : val(o.val) {}
    Obj(Obj&& o) : val(o.val) {}
    void operator=(const Obj& o) {val = o.val;}
    void operator=(Obj&& o) {val = o.val;}
};

int main()
{
    {
        test::out::fmt::Argument<void> arg1;

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierUndefined());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Width{10}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetWidth() == 10);
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Length{10}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetLength() == 10);
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Precision{10}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetPrecision() == 10);
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetWidth() == 10);
        assert(arg1.GetLength() == 20);
    }
    {
         const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<void> arg1{
            specifier,
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetWidth() == 10);
        assert(arg1.GetPrecision() == 20);
    }
    {
        test::out::fmt::Argument<char> arg1;

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierUndefined());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ch;
        test::out::fmt::Argument<char> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierCharacter());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        test::out::fmt::Argument<char*> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ptr;
        test::out::fmt::Argument<void*> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierPointer());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_int;
        test::out::fmt::Argument<int> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierInteger());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_fp;
        test::out::fmt::Argument<double> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierFloatingPoint());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        test::out::fmt::Argument<char*> arg1{
            specifier
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<long> arg1{
            specifier
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_bool;
        test::out::fmt::Argument<bool> arg1{
            specifier
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBoolean());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ch;
        test::out::fmt::Argument<char> arg1{
            specifier,
            test::out::fmt::flag::Value<char>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierCharacter());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<char*>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ptr;
        test::out::fmt::Argument<void*> arg1{
            specifier,
            test::out::fmt::flag::Value<void*>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierPointer());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_int;
        test::out::fmt::Argument<int> arg1{
            specifier,
            test::out::fmt::flag::Value<short>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierInteger());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_fp;
        test::out::fmt::Argument<double> arg1{
            specifier,
            test::out::fmt::flag::Value<double>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierFloatingPoint());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<char*>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<long> arg1{
            specifier,
            test::out::fmt::flag::Value<int>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_bool;
        test::out::fmt::Argument<bool> arg1{
            specifier,
            test::out::fmt::flag::Value<bool>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBoolean());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Value<Obj>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Length{}
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }

    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ch;
        test::out::fmt::Argument<char> arg1{
            specifier,
            test::out::fmt::flag::Value<char>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierCharacter());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<char*>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ptr;
        test::out::fmt::Argument<void*> arg1{
            specifier,
            test::out::fmt::flag::Value<void*>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierPointer());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_int;
        test::out::fmt::Argument<int> arg1{
            specifier,
            test::out::fmt::flag::Value<short>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierInteger());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_fp;
        test::out::fmt::Argument<double> arg1{
            specifier,
            test::out::fmt::flag::Value<double>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierFloatingPoint());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<char*>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        test::out::fmt::Argument<long> arg1{
            specifier,
            test::out::fmt::flag::Value<int>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_bool;
        test::out::fmt::Argument<bool> arg1{
            specifier,
            test::out::fmt::flag::Value<bool>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBoolean());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Value<Obj>{},
            test::out::fmt::flag::Width{},
            test::out::fmt::flag::Precision{}
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
    }

    {
        
        test::out::fmt::Argument<char> arg1{
            test::out::fmt::Definition::FlagType::specifier_ch,
            test::out::fmt::flag::Value<char>('a')
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierCharacter());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue() == 'a');
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        const char * str1 = "test";
        char * str2 = const_cast<char *>(str1);
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<char*>(str2)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        const char * str1 = "test";
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<const char*>(str1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(strcmp(&*(arg1.GetValue()), "test") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        const wchar_t * str1 = L"test";
        wchar_t * str2 = const_cast<wchar_t*>(str1);
        test::out::fmt::Argument<wchar_t*> arg1{
            specifier,
            test::out::fmt::flag::Value<wchar_t*>(str2)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_str;
        const wchar_t * str1 = L"test";
        test::out::fmt::Argument<wchar_t*> arg1{
            specifier,
            test::out::fmt::flag::Value<const wchar_t*>(str1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierString());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(wcscmp(&*(arg1.GetValue()), L"test") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_ptr;
        int val1 = 0;
        test::out::fmt::Argument<void*> arg1{
            specifier,
            test::out::fmt::flag::Value<void*>(&val1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierPointer());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue() == &val1);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_int;
        int val1 = 4;
        test::out::fmt::Argument<int> arg1{
            specifier,
            test::out::fmt::flag::Value<int>(val1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierInteger());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue() == val1);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_fp;
        double val1 = 3.14;
        test::out::fmt::Argument<double> arg1{
            specifier,
            test::out::fmt::flag::Value<double>(val1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierFloatingPoint());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue() == val1);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        const char * str1 = "test1";
        char * str2 = const_cast<char *>(str1);
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<char *>(str2)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(strcmp(&*(arg1.GetValue()), "test1") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        const char * str1 = "test1";
        test::out::fmt::Argument<char*> arg1{
            specifier,
            test::out::fmt::flag::Value<const char *>(str1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(strcmp(&*(arg1.GetValue()), "test1") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        const wchar_t * str1 = L"test1";
        wchar_t * str2 = const_cast<wchar_t *>(str1);
        test::out::fmt::Argument<wchar_t*> arg1{
            specifier,
            test::out::fmt::flag::Value<wchar_t *>(str2)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(wcscmp(&*(arg1.GetValue()), L"test1") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_num_ch;
        const wchar_t * str1 = L"test1";
        test::out::fmt::Argument<wchar_t*> arg1{
            specifier,
            test::out::fmt::flag::Value<const wchar_t *>(str1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierNumberCharacter());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(wcscmp(&*(arg1.GetValue()), L"test1") == 0);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_blank;
        long val1 = 6;
        test::out::fmt::Argument<long> arg1{
            specifier,
            test::out::fmt::flag::Value<long>(val1)
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBlank());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue() == val1);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_bool;
        bool val1 = true;
        test::out::fmt::Argument<bool> arg1{
            specifier,
            test::out::fmt::flag::Value<bool>(val1)
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierBoolean());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue() == val1);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        Obj obj1{10};
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Value<Obj>(obj1)
        };
        
        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());
        assert(arg1.GetValue().val == obj1.val);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Width{4}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetWidth() == 4);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Length{10}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetLength() == 10);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Precision{8}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetPrecision() == 8);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetWidth() == 10);
        assert(arg1.GetLength() == 20);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(!arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetWidth() == 10);
        assert(arg1.GetPrecision() == 20);
    }

    
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        Obj obj1{10};
    
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Width{4},
            test::out::fmt::flag::Value<Obj>(obj1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(!arg1.GetFlag().HasInputLength());
        assert(!arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetWidth() == 4);
        assert(arg1.GetValue().val == obj1.val);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        Obj obj1{10};
    
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Length{10},
            test::out::fmt::flag::Value<Obj>(obj1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetLength() == 10);
        assert(arg1.GetValue().val == obj1.val);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        Obj obj1{10};
    
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Precision{8},
            test::out::fmt::flag::Value<Obj>(obj1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(arg1.GetFlag().HasInputValue());
        assert(!arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetPrecision() == 8);
        assert(arg1.GetValue().val == obj1.val);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        Obj obj1{10};
    
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Length{20},
            test::out::fmt::flag::Value<Obj>(obj1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetWidth() == 10);
        assert(arg1.GetLength() == 20);
        assert(arg1.GetValue().val == obj1.val);
    }
    {
        const auto specifier = 
            test::out::fmt::Definition::FlagType::specifier_object;
        Obj obj1{10};
    
        test::out::fmt::Argument<Obj> arg1{
            specifier,
            test::out::fmt::flag::Width{10},
            test::out::fmt::flag::Precision{20},
            test::out::fmt::flag::Value<Obj>(obj1)
        };

        assert(arg1.GetFlag().IsBad() == false);
        assert(arg1.GetFlag().IsGood() == true);

        assert(arg1.GetFlag().IsSpecifierObject());
        assert(arg1.GetFlag().HasInputValue());
        assert(arg1.GetFlag().HasInputWidth());
        assert(arg1.GetFlag().HasInputLength());
        assert(arg1.GetFlag().HasInputPrecision());

        assert(arg1.GetWidth() == 10);
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue().val == obj1.val);
    }
    return 0;
}
