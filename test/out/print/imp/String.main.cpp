#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/String.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

typedef typename test::out::Definition::FlagType FlagType;

int main()
{
    char * buff = new char[1024];
    wchar_t * wbuff = new wchar_t[1024];
    {
        constexpr auto fmt_flag = 
            test::out::print::String::char_fmt;
        test::out::CString<char> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 0, 0);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::char_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 0, 0);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }

    {
        constexpr auto fmt_flag = 
            test::out::print::String::wchar_fmt;
        test::out::CString<char> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 0, 0);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::wchar_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 0, 0);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }

    {
        constexpr auto fmt_flag = 
            test::out::print::String::w_char_fmt;
        test::out::CString<char> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%10s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 0);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::w_char_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%10s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 0);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::String::w_wchar_fmt;
        test::out::CString<char> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%10ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 10, 0);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::w_wchar_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%10ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 10, 0);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::String::l_char_fmt;
        test::out::CString<char> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%.10s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 0, 10);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::l_char_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%.10s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 0, 10);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::String::l_wchar_fmt;
        test::out::CString<char> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%.10ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 0, 10);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::l_wchar_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%.10ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 0, 10);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::String::wl_char_fmt;
        test::out::CString<char> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%10.20s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 20);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::wl_char_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%10.20s", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 20);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::String::wl_wchar_fmt;
        test::out::CString<char> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = snprintf(buff, 1024, "%10.20ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 10, 20);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::String::wl_wchar_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        int len1 = swprintf(wbuff, 1024, L"%10.20ls", str2);
        int len2 = test::out::print::imp::String<fmt_flag>::Output(out1, 
            &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 10, 20);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }

    delete[] buff;
    buff = nullptr;
    delete[] wbuff;
    wbuff = nullptr;
    return 0;
}
