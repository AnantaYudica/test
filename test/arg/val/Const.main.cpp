#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_VAL_CONST_DLEVEL 0x7f

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/arg/val/Const.h"
#include "test/arg/Value.h"

#include <cassert>
#include <climits>
#include <cfloat>

int main()
{
    test::Pointer<std::uint8_t> blocks1{test::ptr::arg::Array{sizeof(int) * 2}};
    {
        test::arg::val::Const<int> arg_const1;

        assert(arg_const1.Header() == test::arg::Header());
        assert(arg_const1.Size() == 0);
    }
    {
        test::arg::Block blk1{test::arg::Header::Make<int>(), 
            sizeof(int), sizeof(int)};
        test::arg::Value<int> arg_val1{blk1, blocks1};

        assert(arg_val1.Size() == sizeof(int));

        arg_val1 = 20;

        test::arg::val::Const<int> arg_const1{arg_val1};

        assert(*arg_const1 == 20);
        assert(arg_const1 == 20);
        
        test::arg::val::Const<int> arg_const2{arg_const1};

        assert(arg_const2.Header() == arg_const1.Header());
        assert(*arg_const2 == 20);
        assert(arg_const2 == 20);
        
        test::arg::val::Const<int> arg_const3{std::move(arg_const1)};

        assert(arg_const3.Header() == arg_const2.Header());
        assert(*arg_const3 == 20);
        assert(arg_const3 == 20);

        test::arg::val::Const<int> arg_const4;
        arg_const4 = arg_const2;
        
        assert(arg_const4.Header() == arg_const2.Header());
        assert(*arg_const4 == 20);
        assert(arg_const4 == 20);

        test::arg::val::Const<int> arg_const5;
        arg_const5 = std::move(arg_const2);
        
        assert(arg_const5.Header() == arg_const4.Header());
        assert(*arg_const5 == 20);
        assert(arg_const5 == 20);

    }
    return TEST::GetInstance().Status().ReturnValue();
}
