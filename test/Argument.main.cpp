#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/Argument.h"

#include <cassert>
#include <utility>
#include <climits>
#include <cfloat>

int main()
{
    {
        test::Argument arg1{};
        assert((bool)arg1 == false);
        assert(arg1.Size() == 0);
        assert(arg1.AllocationSize() == 0);
        assert(arg1.AllocationSize(0) == 0);
        assert(arg1.Current() == 0);
        assert(arg1.Begin() == arg1.End());
        assert((arg1.Begin() + 1) == arg1.End());
        assert((arg1.Begin() - 1) == arg1.End());
    }
    {
        test::Argument arg1{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        assert((bool)arg1 == true);
        assert(arg1.Size() == 10);
        assert(arg1.AllocationSize() == sizeof(int)*10);
        assert(arg1.AllocationSize(0) == sizeof(int));
        assert(arg1.AllocationSize(1) == sizeof(int));
        assert(arg1.AllocationSize(2) == sizeof(int));
        assert(arg1.AllocationSize(3) == sizeof(int));
        assert(arg1.AllocationSize(4) == sizeof(int));
        assert(arg1.AllocationSize(5) == sizeof(int));
        assert(arg1.AllocationSize(6) == sizeof(int));
        assert(arg1.AllocationSize(7) == sizeof(int));
        assert(arg1.AllocationSize(8) == sizeof(int));
        assert(arg1.AllocationSize(9) == sizeof(int));
        assert(arg1.AllocationSize(10) == 0);
        assert(arg1.Current() == 0);

        {
            int val0, val1, val2, val3, val4, val5, val6,
                val7, val8, val9;

            auto c0 = arg1.Current();
            auto sz0 = (arg1++).Load(val0);
            auto c1 = arg1.Current();
            auto sz1 = (arg1++).Load(val1);
            auto c2 = arg1.Current();
            auto sz2 = (arg1++).Load(val2);
            auto c3 = arg1.Current();
            auto sz3 = (arg1++).Load(val3);
            auto c4 = arg1.Current();
            auto sz4 = (arg1++).Load(val4);
            auto c5 = arg1.Current();
            auto sz5 = (arg1++).Load(val5);
            auto c6 = arg1.Current();
            auto sz6 = (arg1++).Load(val6);
            auto c7 = arg1.Current();
            auto sz7 = (arg1++).Load(val7);
            auto c8 = arg1.Current();
            auto sz8 = (arg1++).Load(val8);
            auto c9 = arg1.Current();
            auto sz9 = (arg1++).Load(val9);

            assert(val0 == 10);
            assert(val1 == 20);
            assert(val2 == 30);
            assert(val3 == 40);
            assert(val4 == 50);
            assert(val5 == 60);
            assert(val6 == 70);
            assert(val7 == 80);
            assert(val8 == 90);
            assert(val9 == 100);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(int));
            assert(sz2 == sizeof(int));
            assert(sz3 == sizeof(int));
            assert(sz4 == sizeof(int));
            assert(sz5 == sizeof(int));
            assert(sz6 == sizeof(int));
            assert(sz7 == sizeof(int));
            assert(sz8 == sizeof(int));
            assert(sz9 == sizeof(int));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
            assert(c7 == 7);
            assert(c8 == 8);
            assert(c9 == 9);
        }
        {
            std::size_t i = 0;
            for(auto it = arg1.Begin(); it != arg1.End(); it++, i++)
            {
                int ld;
                auto sz = it.template Load(ld);
                assert(sz == sizeof(int));
                assert(ld == (10 * (i + 1)));
                assert(it.Current() == i);
            }
        }
        {
            std::size_t i = 9;
            for(auto it = arg1.Begin() + 9; it != arg1.End(); it--, i--)
            {
                int ld;
                auto sz = it.template Load(ld);
                assert(sz == sizeof(int));
                assert(ld == (10 * (i + 1)));
                assert(it.Current() == i);
            }
        }
    }
    {
        const std::size_t size_alloc = sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char) +
            sizeof(long double) + sizeof(short) + sizeof(int*);
        short sh1 = SHRT_MIN;
        int po1 = INT_MIN;
        test::Argument arg1{INT_MAX, 'L', LLONG_MAX, 'a', 
            LDBL_MIN, sh1, &po1};
        assert((bool)arg1 == true);
        assert(arg1.Size() == 7);
        assert(arg1.AllocationSize() == size_alloc);
        assert(arg1.AllocationSize(0) == sizeof(int));
        assert(arg1.AllocationSize(1) == sizeof(char));
        assert(arg1.AllocationSize(2) == sizeof(long long));
        assert(arg1.AllocationSize(3) == sizeof(char));
        assert(arg1.AllocationSize(4) == sizeof(long double));
        assert(arg1.AllocationSize(5) == sizeof(short));
        assert(arg1.AllocationSize(6) == sizeof(int*));
        assert(arg1.AllocationSize(7) == 0);
        assert(arg1.Current() == 0);

        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;

            auto c0 = arg1.Current();
            auto sz0 = (arg1++).Load(val0);
            auto c1 = arg1.Current();
            auto sz1 = (arg1++).Load(val1);
            auto c2 = arg1.Current();
            auto sz2 = (arg1++).Load(val2);
            auto c3 = arg1.Current();
            auto sz3 = (arg1++).Load(val3);
            auto c4 = arg1.Current();
            auto sz4 = (arg1++).Load(val4);
            auto c5 = arg1.Current();
            auto sz5 = (arg1++).Load(val5);
            auto c6 = arg1.Current();
            auto sz6 = (arg1++).Load(val6);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
        }
        test::Argument arg2{arg1.Begin()};
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;

            auto c0 = arg2.Current();
            auto sz0 = (arg2++).Load(val0);
            auto c1 = arg2.Current();
            auto sz1 = (arg2++).Load(val1);
            auto c2 = arg2.Current();
            auto sz2 = (arg2++).Load(val2);
            auto c3 = arg2.Current();
            auto sz3 = (arg2++).Load(val3);
            auto c4 = arg2.Current();
            auto sz4 = (arg2++).Load(val4);
            auto c5 = arg2.Current();
            auto sz5 = (arg2++).Load(val5);
            auto c6 = arg2.Current();
            auto sz6 = (arg2++).Load(val6);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
        }
        test::Argument arg3{std::move(arg2.Begin())};
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;

            auto c0 = arg3.Current();
            auto sz0 = (arg3++).Load(val0);
            auto c1 = arg3.Current();
            auto sz1 = (arg3++).Load(val1);
            auto c2 = arg3.Current();
            auto sz2 = (arg3++).Load(val2);
            auto c3 = arg3.Current();
            auto sz3 = (arg3++).Load(val3);
            auto c4 = arg3.Current();
            auto sz4 = (arg3++).Load(val4);
            auto c5 = arg3.Current();
            auto sz5 = (arg3++).Load(val5);
            auto c6 = arg3.Current();
            auto sz6 = (arg3++).Load(val6);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
        }
        test::Argument arg4;
        arg4 = arg3.Begin();
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;

            auto c0 = arg4.Current();
            auto sz0 = (arg4++).Load(val0);
            auto c1 = arg4.Current();
            auto sz1 = (arg4++).Load(val1);
            auto c2 = arg4.Current();
            auto sz2 = (arg4++).Load(val2);
            auto c3 = arg4.Current();
            auto sz3 = (arg4++).Load(val3);
            auto c4 = arg4.Current();
            auto sz4 = (arg4++).Load(val4);
            auto c5 = arg4.Current();
            auto sz5 = (arg4++).Load(val5);
            auto c6 = arg4.Current();
            auto sz6 = (arg4++).Load(val6);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
        }
        test::Argument arg5;
        arg5 = std::move(arg4.Begin());
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;

            auto c0 = arg5.Current();
            auto sz0 = (arg5++).Load(val0);
            auto c1 = arg5.Current();
            auto sz1 = (arg5++).Load(val1);
            auto c2 = arg5.Current();
            auto sz2 = (arg5++).Load(val2);
            auto c3 = arg5.Current();
            auto sz3 = (arg5++).Load(val3);
            auto c4 = arg5.Current();
            auto sz4 = (arg5++).Load(val4);
            auto c5 = arg5.Current();
            auto sz5 = (arg5++).Load(val5);
            auto c6 = arg5.Current();
            auto sz6 = (arg5++).Load(val6);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
        }
    }
    return TEST::GetInstance().Status().Get();
}
