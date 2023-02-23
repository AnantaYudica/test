#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Pointer.h"
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
            test::out::print::Pointer::ptr_fmt;
        int int1;
        test::out::CString<char> out1;
        int len1 = snprintf(buff, 1024, "%p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 0, 0);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::ptr_fmt;
        int int1;
        test::out::CString<wchar_t> out1;
        int len1 = swprintf(wbuff, 1024, L"%p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 0, 0);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::w_ptr_fmt;
        int int1;
        test::out::CString<char> out1;
        int len1 = snprintf(buff, 1024, "%10p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 10, 0);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::w_ptr_fmt;
        int int1;
        test::out::CString<wchar_t> out1;
        int len1 = swprintf(wbuff, 1024, L"%10p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 10, 0);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }

    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::l_ptr_fmt;
        int int1;
        test::out::CString<char> out1;
        int len1 = snprintf(buff, 1024, "%.10p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 0, 10);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::l_ptr_fmt;
        int int1;
        test::out::CString<wchar_t> out1;
        int len1 = swprintf(wbuff, 1024, L"%.10p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 0, 10);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }

    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::wl_ptr_fmt;
        int int1;
        test::out::CString<char> out1;
        int len1 = snprintf(buff, 1024, "%20.10p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 20, 10);
        
        assert(len1 == len2);
        assert(strcmp(buff, *(out1.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Pointer::wl_ptr_fmt;
        int int1;
        test::out::CString<wchar_t> out1;
        int len1 = swprintf(wbuff, 1024, L"%20.10p", &int1);
        int len2 = test::out::print::imp::Pointer<fmt_flag>::Output(out1, 
            &int1, sizeof(int*), FlagType{}, 20, 10);
        
        assert(len1 == len2);
        assert(wcscmp(wbuff, *(out1.Get())) == 0);
    }

    delete[] buff;
    buff = nullptr;

    delete[] wbuff;
    wbuff = nullptr;

    return 0;
}
