#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_FLAG_DLEVEL 0x7f

#include "test/arg/Flag.h"

#include <cassert>
#include <utility>

int main()
{
    {
        test::arg::Flag f1;
        
        assert(f1.IsBackwardEnd() == true);
        assert(f1.IsForwardEnd() == true);
        assert(f1.IsEnd() == true);

        test::arg::Flag f2(f1);
        
        assert(f1 == f2);
        assert((f1 == f2) == true);
        assert((f1 != f2) == false);
        
        assert(f2.IsBackwardEnd() == true);
        assert(f2.IsForwardEnd() == true);
        assert(f2.IsEnd() == true);

        test::arg::Flag f3(std::move(f2));
        assert(f2 == f3);
        assert((f2 == f3) == true);
        assert((f2 != f3) == false);
        
        assert(f3.IsBackwardEnd() == true);
        assert(f3.IsForwardEnd() == true);
        assert(f3.IsEnd() == true);
    }
    {
        test::arg::Flag f1;
        f1.Reset();

        assert(f1 != test::arg::Flag());

        assert(f1.IsBackwardEnd() == false);
        assert(f1.IsForwardEnd() == false);
        assert(f1.IsEnd() == false);

        test::arg::Flag f2;
        f2 = f1;
        assert(f1 == f2);
        assert(f1.IsBackwardEnd() == false);
        assert(f1.IsForwardEnd() == false);
        assert(f1.IsEnd() == false);

        test::arg::Flag f3;
        f3 = std::move(f2);
        assert(f3 == f2);
        assert(f3.IsBackwardEnd() == false);
        assert(f3.IsForwardEnd() == false);
        assert(f3.IsEnd() == false);


    }
    
    {
        test::arg::Flag f1(10);
        assert(f1.Forward(1, 0, 4) == 1);
        assert(f1.IsBackwardEnd() == false);
        assert(f1.IsForwardEnd() == false);
        assert(f1.IsEnd() == false);
        
        assert(f1.Forward(4, 0, 4) == 4);

        assert(f1.IsBackwardEnd() == false);
        assert(f1.IsForwardEnd() == true);
        assert(f1.IsEnd() == true);

    }
    {
        test::arg::Flag f1(10);
        assert(f1.Backward(1, 3, 4) == 2);
        assert(f1.IsBackwardEnd() == false);
        assert(f1.IsForwardEnd() == false);
        assert(f1.IsEnd() == false);
        
        assert(f1.Backward(4, 3, 4) == 4);

        assert(f1.IsBackwardEnd() == true);
        assert(f1.IsForwardEnd() == false);
        assert(f1.IsEnd() == true);


    }
    return 0;
}
