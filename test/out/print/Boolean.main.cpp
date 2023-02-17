#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Boolean.h"

#include <cassert>
#include <cstring>

int main()
{
    {
        assert((test::out::print::Boolean::bool_fmt &
            test::out::print::Boolean::MaskValue) ==
            test::out::print::Boolean::bool_fmt);
            
        assert((test::out::print::Boolean::w_bool_fmt &
            test::out::print::Boolean::MaskValue) ==
            test::out::print::Boolean::w_bool_fmt);
            
    }
    return 0;
}
