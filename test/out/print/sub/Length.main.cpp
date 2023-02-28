#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/sub/Length.h"

#include <cassert>

int main()
{
    {
        assert((test::out::print::sub::Length::l_fmt &
            test::out::print::sub::Length::MaskValue) ==
            test::out::print::sub::Length::l_fmt);
            
    }
    return 0;
}
