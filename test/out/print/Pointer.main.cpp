#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/Pointer.h"

#include <cassert>

int main()
{
    assert((test::out::print::Pointer::ptr_fmt &
        test::out::print::Pointer::MaskValue) ==
        test::out::print::Pointer::ptr_fmt);
    assert((test::out::print::Pointer::w_ptr_fmt &
        test::out::print::Pointer::MaskValue) ==
        test::out::print::Pointer::w_ptr_fmt);
    assert((test::out::print::Pointer::l_ptr_fmt &
        test::out::print::Pointer::MaskValue) ==
        test::out::print::Pointer::l_ptr_fmt);
    assert((test::out::print::Pointer::wl_ptr_fmt &
        test::out::print::Pointer::MaskValue) ==
        test::out::print::Pointer::wl_ptr_fmt);
    return 0;
}
