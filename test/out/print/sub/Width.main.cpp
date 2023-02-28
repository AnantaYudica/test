#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/sub/Width.h"

#include <cassert>

int main()
{
    {
        assert((test::out::print::sub::Width::w_fmt &
        test::out::print::sub::Width::MaskValue) ==
        test::out::print::sub::Width::w_fmt);

        assert((test::out::print::sub::Width::l_w_fmt &
        test::out::print::sub::Width::MaskValue) ==
        test::out::print::sub::Width::l_w_fmt);
    }
    return 0;
}
