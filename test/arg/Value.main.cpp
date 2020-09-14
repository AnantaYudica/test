#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/arg/Value.h"

#include <cassert>
#include <climits>
#include <cfloat>

int main()
{
    {
        test::arg::Value arg_val1{sizeof(int)};

        assert(arg_val1.AllocationSize() == sizeof(int));

        arg_val1.template Set<int>(0, 20);
        auto val0 = arg_val1.template Get<int>(0);
        assert(*val0 == 20);
    }
    {
        test::arg::Value arg_val1{sizeof(int) * 10};

        assert(arg_val1.AllocationSize() == sizeof(int) * 10);

        arg_val1.template Set<int>(0, 100);
        arg_val1.template Set<int>(sizeof(int) * 1, 200);
        arg_val1.template Set<int>(sizeof(int) * 2, 300);
        arg_val1.template Set<int>(sizeof(int) * 3, 400);
        arg_val1.template Set<int>(sizeof(int) * 4, 500);
        arg_val1.template Set<int>(sizeof(int) * 5, 600);
        arg_val1.template Set<int>(sizeof(int) * 6, 700);
        arg_val1.template Set<int>(sizeof(int) * 7, 800);
        arg_val1.template Set<int>(sizeof(int) * 8, 900);
        arg_val1.template Set<int>(sizeof(int) * 9, -1000);
        auto val0 = arg_val1.template Get<int>(0);
        auto val1 = arg_val1.template Get<int>(sizeof(int) * 1);
        auto val2 = arg_val1.template Get<int>(sizeof(int) * 2);
        auto val3 = arg_val1.template Get<int>(sizeof(int) * 3);
        auto val4 = arg_val1.template Get<int>(sizeof(int) * 4);
        auto val5 = arg_val1.template Get<int>(sizeof(int) * 5);
        auto val6 = arg_val1.template Get<int>(sizeof(int) * 6);
        auto val7 = arg_val1.template Get<int>(sizeof(int) * 7);
        auto val8 = arg_val1.template Get<int>(sizeof(int) * 8);
        auto val9 = arg_val1.template Get<int>(sizeof(int) * 9);
        assert(*val0 == 100);
        assert(*val1 == 200);
        assert(*val2 == 300);
        assert(*val3 == 400);
        assert(*val4 == 500);
        assert(*val5 == 600);
        assert(*val6 == 700);
        assert(*val7 == 800);
        assert(*val8 == 900);
        assert(*val9 == -1000);
    }
    {
        const std::size_t size_alloc = sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char) +
            sizeof(long double) + sizeof(short) + sizeof(int*);
        test::arg::Value arg_val1{size_alloc};
        int p0 = INT_MIN;

        assert(arg_val1.AllocationSize() == size_alloc);

        arg_val1.template Set<int>(0, INT_MAX);
        arg_val1.template Set<char>(sizeof(int), 'L');
        arg_val1.template Set<long long>(sizeof(int) +
            sizeof(char), LLONG_MAX);
        arg_val1.template Set<char>(sizeof(int) + sizeof(char) +
            sizeof(long long), 'a');
        arg_val1.template Set<long double>(sizeof(int) + sizeof(char) +
            sizeof(long long) + sizeof(char), LDBL_MIN);
        arg_val1.template Set<short>(sizeof(int) + sizeof(char) +
            sizeof(long long) + sizeof(char) + sizeof(long double), SHRT_MIN);
        arg_val1.template Set<int*>(sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char) +
            sizeof(long double) + sizeof(short), &p0);
        
        auto val0 = arg_val1.template Get<int>(0);
        auto val1 = arg_val1.template Get<char>(sizeof(int));
        auto val2 = arg_val1.template Get<long long>(sizeof(int) +
            sizeof(char));
        auto val3 = arg_val1.template Get<char>(sizeof(int) +
            sizeof(char) + sizeof(long long));
        auto val4 = arg_val1.template Get<long double>(sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char));
        auto val5 = arg_val1.template Get<short>(sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char) +
            sizeof(long double));
        auto val6 = arg_val1.template Get<int*>(sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char) +
            sizeof(long double) + sizeof(short));
        assert(*val0 == INT_MAX);
        assert(*val1 == 'L');
        assert(*val2 == LLONG_MAX);
        assert(*val3 == 'a');
        assert(*val4 == LDBL_MIN);
        assert(*val5 == SHRT_MIN);
        assert(*val6 == &p0);

        test::arg::Value arg_val2{arg_val1};
        {
            assert(arg_val2 == arg_val1);

            auto val2_0 = arg_val2.template Get<int>(0);
            auto val2_1 = arg_val2.template Get<char>(sizeof(int));
            auto val2_2 = arg_val2.template Get<long long>(sizeof(int) +
                sizeof(char));
            auto val2_3 = arg_val2.template Get<char>(sizeof(int) +
                sizeof(char) + sizeof(long long));
            auto val2_4 = arg_val2.template Get<long double>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char));
            auto val2_5 = arg_val2.template Get<short>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double));
            auto val2_6 = arg_val2.template Get<int*>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double) + sizeof(short));
            assert(*val2_0 == INT_MAX);
            assert(*val2_1 == 'L');
            assert(*val2_2 == LLONG_MAX);
            assert(*val2_3 == 'a');
            assert(*val2_4 == LDBL_MIN);
            assert(*val2_5 == SHRT_MIN);
            assert(*val2_6 == &p0);
        }
        test::arg::Value arg_val3{std::move(arg_val2)};
        {
            assert(arg_val3 == arg_val1);
            assert(arg_val2 == arg_val1);

            auto val2_0 = arg_val3.template Get<int>(0);
            auto val2_1 = arg_val3.template Get<char>(sizeof(int));
            auto val2_2 = arg_val3.template Get<long long>(sizeof(int) +
                sizeof(char));
            auto val2_3 = arg_val3.template Get<char>(sizeof(int) +
                sizeof(char) + sizeof(long long));
            auto val2_4 = arg_val3.template Get<long double>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char));
            auto val2_5 = arg_val3.template Get<short>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double));
            auto val2_6 = arg_val3.template Get<int*>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double) + sizeof(short));
            assert(*val2_0 == INT_MAX);
            assert(*val2_1 == 'L');
            assert(*val2_2 == LLONG_MAX);
            assert(*val2_3 == 'a');
            assert(*val2_4 == LDBL_MIN);
            assert(*val2_5 == SHRT_MIN);
            assert(*val2_6 == &p0);
        }
        {
            assert(arg_val2 == arg_val1);

            auto val2_0 = arg_val2.template Get<int>(0);
            auto val2_1 = arg_val2.template Get<char>(sizeof(int));
            auto val2_2 = arg_val2.template Get<long long>(sizeof(int) +
                sizeof(char));
            auto val2_3 = arg_val2.template Get<char>(sizeof(int) +
                sizeof(char) + sizeof(long long));
            auto val2_4 = arg_val2.template Get<long double>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char));
            auto val2_5 = arg_val2.template Get<short>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double));
            auto val2_6 = arg_val2.template Get<int*>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double) + sizeof(short));
            assert(*val2_0 == INT_MAX);
            assert(*val2_1 == 'L');
            assert(*val2_2 == LLONG_MAX);
            assert(*val2_3 == 'a');
            assert(*val2_4 == LDBL_MIN);
            assert(*val2_5 == SHRT_MIN);
            assert(*val2_6 == &p0);
        }
        
        test::arg::Value arg_val4{};
        arg_val4 = arg_val3;
        {
            assert(arg_val3 == arg_val1);

            auto val2_0 = arg_val3.template Get<int>(0);
            auto val2_1 = arg_val3.template Get<char>(sizeof(int));
            auto val2_2 = arg_val3.template Get<long long>(sizeof(int) +
                sizeof(char));
            auto val2_3 = arg_val3.template Get<char>(sizeof(int) +
                sizeof(char) + sizeof(long long));
            auto val2_4 = arg_val3.template Get<long double>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char));
            auto val2_5 = arg_val3.template Get<short>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double));
            auto val2_6 = arg_val3.template Get<int*>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double) + sizeof(short));
            assert(*val2_0 == INT_MAX);
            assert(*val2_1 == 'L');
            assert(*val2_2 == LLONG_MAX);
            assert(*val2_3 == 'a');
            assert(*val2_4 == LDBL_MIN);
            assert(*val2_5 == SHRT_MIN);
            assert(*val2_6 == &p0);
        }
        
        test::arg::Value arg_val5{};
        arg_val5 = std::move(arg_val4);
        {
            assert(arg_val5 == arg_val1);
            assert(arg_val4 == arg_val1);

            auto val2_0 = arg_val5.template Get<int>(0);
            auto val2_1 = arg_val5.template Get<char>(sizeof(int));
            auto val2_2 = arg_val5.template Get<long long>(sizeof(int) +
                sizeof(char));
            auto val2_3 = arg_val5.template Get<char>(sizeof(int) +
                sizeof(char) + sizeof(long long));
            auto val2_4 = arg_val5.template Get<long double>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char));
            auto val2_5 = arg_val5.template Get<short>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double));
            auto val2_6 = arg_val5.template Get<int*>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double) + sizeof(short));
            assert(*val2_0 == INT_MAX);
            assert(*val2_1 == 'L');
            assert(*val2_2 == LLONG_MAX);
            assert(*val2_3 == 'a');
            assert(*val2_4 == LDBL_MIN);
            assert(*val2_5 == SHRT_MIN);
            assert(*val2_6 == &p0);
        }
        {
            assert(arg_val4 == arg_val1);

            auto val2_0 = arg_val4.template Get<int>(0);
            auto val2_1 = arg_val4.template Get<char>(sizeof(int));
            auto val2_2 = arg_val4.template Get<long long>(sizeof(int) +
                sizeof(char));
            auto val2_3 = arg_val4.template Get<char>(sizeof(int) +
                sizeof(char) + sizeof(long long));
            auto val2_4 = arg_val4.template Get<long double>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char));
            auto val2_5 = arg_val4.template Get<short>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double));
            auto val2_6 = arg_val4.template Get<int*>(sizeof(int) +
                sizeof(char) + sizeof(long long) + sizeof(char) +
                sizeof(long double) + sizeof(short));
            assert(*val2_0 == INT_MAX);
            assert(*val2_1 == 'L');
            assert(*val2_2 == LLONG_MAX);
            assert(*val2_3 == 'a');
            assert(*val2_4 == LDBL_MIN);
            assert(*val2_5 == SHRT_MIN);
            assert(*val2_6 == &p0);
        }
    }
    return TEST::GetInstance().Status().Get();
}
