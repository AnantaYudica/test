#include "test/out/print/Width.h"

#include <cassert>
#include <cstring>

int main()
{
    typedef test::out::fmt::FlagType FlagType;
    {
        test::CString<char> val_cstr1{"123"};
        auto cstr1 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 10);
        assert(strcmp(*cstr1, "       123") == 0);
        assert(cstr1.Size() == 10);
        
        auto cstr2 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, -10);
        assert(strcmp(*cstr2, "123       ") == 0);
        assert(cstr2.Size() == 10);

        auto cstr3 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 3);
        assert(strcmp(*cstr3, "123") == 0);
        assert(cstr3.Size() == 3);
        
        auto cstr4 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, -3);
        assert(strcmp(*cstr4, "123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 0);
        assert(strcmp(*cstr5, "123") == 0);
        assert(cstr5.Size() == 3);
        
        auto cstr6 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 0);
        assert(strcmp(*cstr6, "123") == 0);
        assert(cstr6.Size() == 3);
        
        auto cstr7 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1);
        assert(strcmp(*cstr7, "123") == 0);
        assert(cstr7.Size() == 3);
        
        auto cstr8 = test::out::print::Width::CStr<char, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1);
        assert(strcmp(*cstr8, "123") == 0);
        assert(cstr8.Size() == 3);
    }
    {
        test::CString<wchar_t> val_cstr1{L"123"};
        auto cstr1 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 10);
        assert(wcscmp(*cstr1, L"       123") == 0);
        assert(cstr1.Size() == 10);
        
        auto cstr2 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, -10);
        assert(wcscmp(*cstr2, L"123       ") == 0);
        assert(cstr2.Size() == 10);

        auto cstr3 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 3);
        assert(wcscmp(*cstr3, L"123") == 0);
        assert(cstr3.Size() == 3);
        
        auto cstr4 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, -3);
        assert(wcscmp(*cstr4, L"123") == 0);
        assert(cstr4.Size() == 3);
        
        auto cstr5 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 0);
        assert(wcscmp(*cstr5, L"123") == 0);
        assert(cstr5.Size() == 3);
        
        auto cstr6 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1, 0);
        assert(wcscmp(*cstr6, L"123") == 0);
        assert(cstr6.Size() == 3);
        
        auto cstr7 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1);
        assert(wcscmp(*cstr7, L"123") == 0);
        assert(cstr7.Size() == 3);
        
        auto cstr8 = test::out::print::Width::CStr<wchar_t, 
            FlagType::specifier_sub_width |
            FlagType::specifier_int>(val_cstr1);
        assert(wcscmp(*cstr8, L"123") == 0);
        assert(cstr8.Size() == 3);
    }

    return 0;
}
