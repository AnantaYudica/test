#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Character.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

typedef typename test::out::Definition::FlagType FlagType;
int main()
{
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::char_fmt;
        test::out::CString<char> out1;
        char ch1 = 'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(char), FlagType{}, 0, 0);

        assert(sz1 == 1);
        assert(strcmp(*(out1.Get()), "A") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::w_char_fmt;
        test::out::CString<char> out1;
        char ch1 = 'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(char), FlagType{}, 10, 0);

        assert(sz1 == 10);
        assert(strcmp(*(out1.Get()), "         A") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::wchar_fmt;
        test::out::CString<char> out1;
        wchar_t ch1 = L'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(wchar_t), FlagType{}, 0, 0);

        assert(sz1 == 1);
        assert(strcmp(*(out1.Get()), "A") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::w_wchar_fmt;
        test::out::CString<char> out1;
        wchar_t ch1 = L'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(wchar_t), FlagType{}, 10, 0);

        assert(sz1 == 10);
        assert(strcmp(*(out1.Get()), "         A") == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::char_fmt;
        test::out::CString<wchar_t> out1;
        char ch1 = 'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(char), FlagType{}, 0, 0);

        assert(sz1 == 1);
        assert(wcscmp(*(out1.Get()), L"A") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::w_char_fmt;
        test::out::CString<wchar_t> out1;
        char ch1 = 'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(char), FlagType{}, 10, 0);

        assert(sz1 == 10);
        assert(wcscmp(*(out1.Get()), L"         A") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::wchar_fmt;
        test::out::CString<wchar_t> out1;
        wchar_t ch1 = L'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(wchar_t), FlagType{}, 0, 0);

        assert(sz1 == 1);
        assert(wcscmp(*(out1.Get()), L"A") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Character::w_wchar_fmt;
        test::out::CString<wchar_t> out1;
        wchar_t ch1 = L'A';
        auto sz1 = test::out::print::imp::Character<fmt_flag>::Output(out1, 
            &ch1, sizeof(wchar_t), FlagType{}, 10, 0);

        assert(sz1 == 10);
        assert(wcscmp(*(out1.Get()), L"         A") == 0);
    }
    return 0;
}
