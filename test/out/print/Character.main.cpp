#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Character.h"

#include <cassert>
#include <cstring>

int main()
{
    {
        assert((test::out::print::Character::char_fmt &
            test::out::print::Character::MaskValue) ==
            test::out::print::Character::char_fmt);
            
        assert((test::out::print::Character::w_char_fmt &
            test::out::print::Character::MaskValue) ==
            test::out::print::Character::w_char_fmt);
            
        assert((test::out::print::Character::wchar_fmt &
            test::out::print::Character::MaskValue) ==
            test::out::print::Character::wchar_fmt);
            
        assert((test::out::print::Character::w_wchar_fmt &
            test::out::print::Character::MaskValue) ==
            test::out::print::Character::w_wchar_fmt);
    }
    return 0;
}
