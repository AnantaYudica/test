#include "test/out/print/specifier/Character.h"
#include "test/out/CString.h"

#include <cstring>
#include <cwchar>
#include <cassert>

int main()
{
    int wd1 = -4;
    char ch1 = 'A';
    wchar_t wch1 = L'Z';
    
    {
        test::out::CString<char> out_cstr1;
        auto out1 = test::out::print::specifier::Character<char, 
            test::out::print::Character::char_fmt>::Output(out_cstr1,
                nullptr, &ch1);
        assert(out1 == 1);
        assert(strncmp("A", *(out_cstr1.Get()), 1) == 0);
    }
    {
        test::out::CString<wchar_t> out_cstr1;
        auto out1 = test::out::print::specifier::Character<wchar_t, 
            test::out::print::Character::char_fmt>::Output(out_cstr1,
                nullptr, &ch1);
        assert(out1 == 1);
        assert(wcsncmp(L"A", *(out_cstr1.Get()), 1) == 0);
    }
    {
        test::out::CString<char> out_cstr1;
        auto out1 = test::out::print::specifier::Character<char, 
            test::out::print::Character::wchar_fmt>::Output(out_cstr1,
                nullptr, &wch1);
        assert(out1 == 1);
        assert(strncmp("Z", *(out_cstr1.Get()), 1) == 0);
    }
    {
        test::out::CString<wchar_t> out_cstr1;
        auto out1 = test::out::print::specifier::Character<wchar_t, 
            test::out::print::Character::wchar_fmt>::Output(out_cstr1,
                nullptr, &wch1);
        assert(out1 == 1);
        assert(wcsncmp(L"Z", *(out_cstr1.Get()), 1) == 0);
    }
    {
        test::out::CString<char> out_cstr1;
        auto out1 = test::out::print::specifier::Character<char, 
            test::out::print::Character::w_char_fmt>::Output(out_cstr1,
                &wd1, &ch1);
        assert(out1 == 4);
        assert(strncmp("A   ", *(out_cstr1.Get()), 4) == 0);
    }
    {
        test::out::CString<wchar_t> out_cstr1;
        auto out1 = test::out::print::specifier::Character<wchar_t, 
            test::out::print::Character::w_char_fmt>::Output(out_cstr1,
                &wd1, &ch1);
        assert(out1 == 4);
        assert(wcsncmp(L"A   ", *(out_cstr1.Get()), 4) == 0);
    }
    {
        test::out::CString<char> out_cstr1;
        auto out1 = test::out::print::specifier::Character<char, 
            test::out::print::Character::w_wchar_fmt>::Output(out_cstr1,
                &wd1, &wch1);
        assert(out1 == 4);
        assert(strncmp("Z   ", *(out_cstr1.Get()), 4) == 0);
    }
    {
        test::out::CString<wchar_t> out_cstr1;
        auto out1 = test::out::print::specifier::Character<wchar_t, 
            test::out::print::Character::w_wchar_fmt>::Output(out_cstr1,
                &wd1, &wch1);
        assert(out1 == 4);
        assert(wcsncmp(L"Z   ", *(out_cstr1.Get()), 4) == 0);
    }

    return 0;
}
