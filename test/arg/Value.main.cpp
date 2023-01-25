#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_VALUE_DLEVEL 0x7f

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/arg/Value.h"

#include <cassert>
#include <climits>
#include <cfloat>

int main()
{
    test::Pointer<std::uint8_t> blocks1{test::ptr::arg::Array{sizeof(int) * 2}};
    {
        test::arg::Value<int> arg_val1;

        assert(arg_val1.Header() == test::arg::Header());
        assert(arg_val1.Size() == 0);
    }
    {
        test::arg::Block blk1{test::arg::Header::Make<int>(), 0, sizeof(int)};
        test::arg::Value<int> arg_val1{blk1, blocks1};

        assert(arg_val1.Size() == sizeof(int));

        arg_val1 = 20;
        assert(*arg_val1 == 20);
        assert(arg_val1 == 20);
        
        test::arg::Value<int> arg_val2{arg_val1};

        assert(arg_val2.Header() == arg_val1.Header());
        assert(*arg_val2 == 20);
        assert(arg_val2 == 20);
        
        test::arg::Value<int> arg_val3{std::move(arg_val1)};

        assert(arg_val3.Header() == arg_val2.Header());
        assert(*arg_val3 == 20);
        assert(arg_val3 == 20);

        test::arg::Value<int> arg_val4;
        arg_val4 = arg_val2;
        
        assert(arg_val4.Header() == arg_val2.Header());
        assert(*arg_val4 == 20);
        assert(arg_val4 == 20);

        test::arg::Value<int> arg_val5;
        arg_val5 = std::move(arg_val2);
        
        assert(arg_val5.Header() == arg_val4.Header());
        assert(*arg_val5 == 20);
        assert(arg_val5 == 20);

    }
    return TEST::GetInstance().Status().ReturnValue();
}
