#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/sub/Width.h"
#include "test/out/print/imp/String.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

typedef typename test::out::Definition::FlagType FlagType;

int main()
{
    {
        typedef test::out::Definition::FormatOutputFuncType<char> 
            FormatOutputCharFuncType;
        constexpr auto fmt_flag = 
            test::out::print::sub::Width::w_fmt;
        constexpr auto str_fmt_flag = 
            test::out::print::String::char_fmt;
        test::out::CString<char> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        const std::size_t len = test::out::print::imp::sub::
            Width<fmt_flag>::Output(
                (FormatOutputCharFuncType)&test::out::print::imp::
                    String<str_fmt_flag>::Output,
                out1, &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 0);
        
        assert(len == 10);
        assert(strcmp(*(out1.Get()), "  1234Test") == 0);
    }
    {
        typedef test::out::Definition::FormatOutputFuncType<char> 
            FormatOutputCharFuncType;
        constexpr auto fmt_flag = 
            test::out::print::sub::Width::w_fmt;
        constexpr auto str_fmt_flag = 
            test::out::print::String::char_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        const std::size_t len = test::out::print::imp::sub::
            Width<fmt_flag>::Output(
                (FormatOutputCharFuncType)&test::out::print::imp::
                    String<str_fmt_flag>::Output,
                out1, &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 0);
        
        assert(len == 10);
        assert(wcscmp(*(out1.Get()), L"  1234Test") == 0);
    }
    {
        typedef test::out::Definition::FormatOutputFuncType<char> 
            FormatOutputCharFuncType;
        constexpr auto fmt_flag = 
            test::out::print::sub::Width::w_fmt;
        constexpr auto str_fmt_flag = 
            test::out::print::String::wchar_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        const std::size_t len = test::out::print::imp::sub::
            Width<fmt_flag>::Output(
                (FormatOutputCharFuncType)&test::out::print::imp::
                    String<str_fmt_flag>::Output,
                out1, &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 10, 0);
        
        assert(len == 10);
        assert(wcscmp(*(out1.Get()), L"  1234Test") == 0);
    }
    
    {
        typedef test::out::Definition::FormatOutputFuncType<char> 
            FormatOutputCharFuncType;
        constexpr auto fmt_flag = 
            test::out::print::sub::Width::l_w_fmt;
        constexpr auto str_fmt_flag = 
            test::out::print::String::char_fmt;
        test::out::CString<char> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        const std::size_t len = test::out::print::imp::sub::
            Width<fmt_flag>::Output(
                (FormatOutputCharFuncType)&test::out::print::imp::
                    String<str_fmt_flag>::Output,
                out1, &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 4);
        
        assert(len == 10);
        assert(strcmp(*(out1.Get()), "      1234") == 0);
    }
    {
        typedef test::out::Definition::FormatOutputFuncType<char> 
            FormatOutputCharFuncType;
        constexpr auto fmt_flag = 
            test::out::print::sub::Width::l_w_fmt;
        constexpr auto str_fmt_flag = 
            test::out::print::String::char_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<char> str1{test::ptr::arg::Array{10}};
        const char str2[] = "1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        const std::size_t len = test::out::print::imp::sub::
            Width<fmt_flag>::Output(
                (FormatOutputCharFuncType)&test::out::print::imp::
                    String<str_fmt_flag>::Output,
                out1, &str1, sizeof(test::Pointer<char>*), FlagType{}, 10, 4);
        
        assert(len == 10);
        assert(wcscmp(*(out1.Get()), L"      1234") == 0);
    }
    {
        typedef test::out::Definition::FormatOutputFuncType<char> 
            FormatOutputCharFuncType;
        constexpr auto fmt_flag = 
            test::out::print::sub::Width::l_w_fmt;
        constexpr auto str_fmt_flag = 
            test::out::print::String::wchar_fmt;
        test::out::CString<wchar_t> out1;
        test::Pointer<wchar_t> str1{test::ptr::arg::Array{10}};
        const wchar_t str2[] = L"1234Test";
        memcpy(&*str1, str2, sizeof(str2));
        const std::size_t len = test::out::print::imp::sub::
            Width<fmt_flag>::Output(
                (FormatOutputCharFuncType)&test::out::print::imp::
                    String<str_fmt_flag>::Output,
                out1, &str1, sizeof(test::Pointer<wchar_t>*), FlagType{}, 10, 4);
        
        assert(len == 10);
        assert(wcscmp(*(out1.Get()), L"      1234") == 0);
    }
    return 0;
}
