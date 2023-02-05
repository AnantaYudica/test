#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Nothing.h"

#include <cassert>

int main()
{
    {
        test::out::fmt::arg::Nothing arg1;
        
        assert(arg1.GetFlag().IsSpecifierBlank() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);

        assert(arg1.GetFlag().IsDefine() == false);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
    }
    {
        test::out::fmt::arg::Nothing arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierBlank() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        
        assert(arg1.GetFlag().IsDefine() == false);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::Nothing arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierBlank() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == false);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::Nothing arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierBlank() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        
        assert(arg1.GetFlag().IsDefine() == false);
        assert(arg1.GetFlag().IsDefineSigned() == false);
        assert(arg1.GetFlag().IsDefineUnsigned() == false);
        assert(arg1.GetPrecision() == 20);
    }
    return 0;
}
