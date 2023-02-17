#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Boolean.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

typedef typename test::out::Definition::FlagType FlagType;

int main()
{
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::bool_fmt;
        test::out::CString<char> out1;
        bool b1 = true;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 0, 0);

        const auto true_cstr = test::def::cstr::val::Boolean::TrueCStr<char>();
        assert(sz1 == true_cstr.Size());
        assert(strcmp(*(out1.Get()), *true_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::bool_fmt;
        test::out::CString<char> out1;
        bool b1 = false;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 0, 0);

        const auto false_cstr = test::def::cstr::val::Boolean::FalseCStr<char>();
        assert(sz1 == false_cstr.Size());
        assert(strcmp(*(out1.Get()), *false_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::w_bool_fmt;
        test::out::CString<char> out1;
        bool b1 = true;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 10, 0);

        const auto true_cstr = test::def::cstr::val::Boolean::TrueCStr<char>();
        assert(sz1 == 10);
        const std::size_t bg = 10 - true_cstr.Size();
        assert(strcmp(*(out1.Get()) + bg, *true_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::w_bool_fmt;
        test::out::CString<char> out1;
        bool b1 = false;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 10, 0);

        const auto false_cstr = test::def::cstr::val::Boolean::FalseCStr<char>();
        assert(sz1 == 10);
        const std::size_t bg = 10 - false_cstr.Size();
        assert(strcmp(*(out1.Get()) + bg, *false_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::bool_fmt;
        test::out::CString<wchar_t> out1;
        bool b1 = true;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 0, 0);

        const auto true_cstr = test::def::cstr::val::Boolean::TrueCStr<wchar_t>();
        assert(sz1 == true_cstr.Size());
        assert(wcscmp(*(out1.Get()), *true_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::bool_fmt;
        test::out::CString<wchar_t> out1;
        bool b1 = false;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 0, 0);

        const auto false_cstr = test::def::cstr::val::Boolean::FalseCStr<wchar_t>();
        assert(sz1 == false_cstr.Size());
        assert(wcscmp(*(out1.Get()), *false_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::w_bool_fmt;
        test::out::CString<wchar_t> out1;
        bool b1 = true;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 10, 0);

        const auto true_cstr = test::def::cstr::val::Boolean::TrueCStr<wchar_t>();
        assert(sz1 == 10);
        const std::size_t bg = 10 - true_cstr.Size();
        assert(wcscmp(*(out1.Get()) + bg, *true_cstr) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Boolean::w_bool_fmt;
        test::out::CString<wchar_t> out1;
        bool b1 = false;
        auto sz1 = test::out::print::imp::Boolean<fmt_flag>::Output(out1, 
            &b1, sizeof(bool), FlagType{}, 10, 0);

        const auto false_cstr = test::def::cstr::val::Boolean::FalseCStr<wchar_t>();
        assert(sz1 == 10);
        const std::size_t bg = 10 - false_cstr.Size();
        assert(wcscmp(*(out1.Get()) + bg, *false_cstr) == 0);
    }
    return 0;
}
