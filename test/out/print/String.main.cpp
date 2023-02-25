#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/String.h"

#include <cassert>

int main()
{
    
    assert((test::out::print::String::char_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::char_fmt);
    assert((test::out::print::String::wchar_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::wchar_fmt);

    assert((test::out::print::String::w_char_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::w_char_fmt);
    assert((test::out::print::String::w_wchar_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::w_wchar_fmt);

    assert((test::out::print::String::l_char_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::l_char_fmt);
    assert((test::out::print::String::l_wchar_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::l_wchar_fmt);

    assert((test::out::print::String::wl_char_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::wl_char_fmt);
    assert((test::out::print::String::wl_wchar_fmt &
        test::out::print::String::MaskValue) ==
        test::out::print::String::wl_wchar_fmt);
    return 0;
}
