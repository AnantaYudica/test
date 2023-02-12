#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/arg/Pointer.h"

#include <cassert>

int main()
{
    {
        test::out::fmt::arg::Pointer<void*> arg1;
        
        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
    }
    {
        test::out::fmt::arg::Pointer<void*> arg1{
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == false);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
    }
    

    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a};

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue() == &a);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetValue() == &a);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(arg1.GetValue() == &a);
    }
    {
        int a;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue() == &a);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a};

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetValue() == &a);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Width{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == true);
        assert(arg1.GetFlag().HasInputLength() == false);
        assert(arg1.GetFlag().HasInputPrecision() == false);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetWidth() == 20);
        assert(arg1.GetValue() == &a);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Length{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetLength() == 20);
        assert(arg1.GetValue() == &a);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<void*> arg1{&a,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue() == &a);
    }
    {
        const int a = 4;
        test::out::fmt::arg::Pointer<int*> arg1{&a,
            test::out::fmt::flag::Precision{20}
        };

        assert(arg1.GetFlag().IsSpecifierPointer() == true);
        assert(arg1.GetFlag().HasInputValue() == true);
        assert(arg1.GetFlag().HasInputWidth() == false);
        assert(arg1.GetFlag().HasInputLength() == true);
        assert(arg1.GetFlag().HasInputPrecision() == true);
        assert(arg1.GetFlag().HasOutput() == false);
        assert(arg1.GetFlag().GetDefine() == (arg1.GetFlag().define_int |
            arg1.GetFlag().define_signed));
        assert(arg1.GetPrecision() == 20);
        assert(arg1.GetValue() == &a);

    }
    return 0;
}
