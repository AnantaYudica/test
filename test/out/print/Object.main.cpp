#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/Object.h"

#include <cassert>

int main()
{
    assert((test::out::print::Object::obj_fmt &
        test::out::print::Object::MaskValue) ==
        test::out::print::Object::obj_fmt);

    assert((test::out::print::Object::w_obj_fmt &
        test::out::print::Object::MaskValue) ==
        test::out::print::Object::w_obj_fmt);
        
    assert((test::out::print::Object::l_obj_fmt &
        test::out::print::Object::MaskValue) ==
        test::out::print::Object::l_obj_fmt);
        
    assert((test::out::print::Object::wl_obj_fmt &
        test::out::print::Object::MaskValue) ==
        test::out::print::Object::wl_obj_fmt);
        
    return 0;
}
