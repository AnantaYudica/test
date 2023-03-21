#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#define TEST_ARGUMENT_DLEVEL 0x7f

#include "test/Argument.h"

#include <cassert>
#include <utility>
#include <climits>
#include <cfloat>

static int count_obj = 0;

struct Obj
{
    char ch;
    int v1;
    long v2;
    Obj() = delete;
    Obj(int v) : ch('a'), v1(v), v2(-1) {++count_obj;}
    Obj(const Obj& cpy) : ch(cpy.ch) , v1(cpy.v1), v2(-1) {++count_obj;}
    Obj(Obj&& mov) : ch(mov.ch) , v1(mov.v1), v2(-1) {++count_obj;}
    void operator=(const Obj& cpy)
    {
        ch = cpy.ch;
        v1 = cpy.v1;
        v2 = -1;
    }
    ~Obj() {--count_obj;}
};

int main()
{
    {
        test::Argument arg1{};
        test::arg::Structure& struc_arg1 = arg1;
        assert((bool)arg1 == false);
        assert(arg1.Size() == 0);
        assert(struc_arg1.AllocationSize() == 0);
        assert(arg1.AllocationSize() == 0);
        assert(arg1.Current() == 0);
        assert(arg1.Begin() == arg1.End());
        assert((arg1.Begin() + 1) == arg1.End());
        assert((arg1.Begin() - 1) == arg1.End());
    }
    {
        test::Argument arg1{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        test::arg::Structure& struc_arg1 = arg1;
        assert((bool)arg1 == true);
        assert(arg1.Size() == 10);
        assert(struc_arg1.AllocationSize() == sizeof(int)*10);
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(int));
        assert(arg1.AllocationSize() == 0);
        assert(arg1.Current() == 10);

        {
            int val0, val1, val2, val3, val4, val5, val6,
                val7, val8, val9;

            auto arg2 = arg1.Begin();

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
            auto c7 = arg2.Current();
            auto sz7 = (arg2++).Load(val7);
            auto c8 = arg2.Current();
            auto sz8 = (arg2++).Load(val8);
            auto c9 = arg2.Current();
            auto sz9 = (arg2++).Load(val9);

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
            sizeof(long double) + sizeof(short) + sizeof(int*) + 
            sizeof(Obj);
        short sh1 = SHRT_MIN;
        int po1 = INT_MIN;
        test::Argument arg1{INT_MAX, 'L', LLONG_MAX, 'a', 
            LDBL_MIN, sh1, &po1, Obj{255}};
        test::arg::Structure& struc_arg1 = arg1;
        assert((bool)arg1 == true);
        assert(arg1.Size() == 8);
        assert((arg1.End() - arg1.Begin()) == 8);
        assert(struc_arg1.AllocationSize() == size_alloc);

        assert((arg1++).AllocationSize() == sizeof(int));
        assert((arg1++).AllocationSize() == sizeof(char));
        assert((arg1++).AllocationSize() == sizeof(long long));
        assert((arg1++).AllocationSize() == sizeof(char));
        assert((arg1++).AllocationSize() == sizeof(long double));
        assert((arg1++).AllocationSize() == sizeof(short));
        assert((arg1++).AllocationSize() == sizeof(int*));
        assert((arg1++).AllocationSize() == sizeof(Obj));
        assert(arg1.AllocationSize() == 0);
        assert(arg1.Current() == 8);

        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;
            Obj val7{0};

            auto arg2 = arg1.Begin();

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
            auto c7 = arg2.Current();
            auto sz7 = (arg2++).Load(val7);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            assert(val7.ch == 'a');
            assert(val7.v1 == 255);
            assert(val7.v2 == -1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            assert(sz7 == sizeof(Obj));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
            assert(c7 == 7);
        }
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;
            Obj val7{0};

            test::Argument arg2{arg1.Begin()};

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
            auto c7 = arg2.Current();
            auto sz7 = (arg2++).Load(val7);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            assert(val7.ch == 'a');
            assert(val7.v1 == 255);
            assert(val7.v2 == -1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            assert(sz7 == sizeof(Obj));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
            assert(c7 == 7);
        }
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;
            Obj val7{0};
            
            auto arg2 = arg1.Begin();
            test::Argument arg3{std::move(arg2)};

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
            auto c7 = arg3.Current();
            auto sz7 = (arg3++).Load(val7);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            assert(val7.ch == 'a');
            assert(val7.v1 == 255);
            assert(val7.v2 == -1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            assert(sz7 == sizeof(Obj));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
            assert(c7 == 7);
        }
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;
            Obj val7{0};
            
            test::Argument arg2;
            arg2 = arg1.Begin();

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
            auto c7 = arg2.Current();
            auto sz7 = (arg2++).Load(val7);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            assert(val7.ch == 'a');
            assert(val7.v1 == 255);
            assert(val7.v2 == -1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            assert(sz7 == sizeof(Obj));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
            assert(c7 == 7);
        }
        {
            int val0;
            char val1;
            long long val2;
            char val3;
            long double val4;
            short val5;
            int* val6;
            Obj val7{0};
            

            auto arg2 = arg1.Begin();
            test::Argument arg3;
            arg3 = std::move(arg2);

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
            auto c7 = arg3.Current();
            auto sz7 = (arg3++).Load(val7);

            assert(val0 == INT_MAX);
            assert(val1 == 'L');
            assert(val2 == LLONG_MAX);
            assert(val3 == 'a');
            assert(val4 == LDBL_MIN);
            assert(val5 == sh1);
            assert(val6 == &po1);
            assert(val7.ch == 'a');
            assert(val7.v1 == 255);
            assert(val7.v2 == -1);
            
            assert(sz0 == sizeof(int));
            assert(sz1 == sizeof(char));
            assert(sz2 == sizeof(long long));
            assert(sz3 == sizeof(char));
            assert(sz4 == sizeof(long double));
            assert(sz5 == sizeof(short));
            assert(sz6 == sizeof(int*));
            assert(sz7 == sizeof(Obj));
            
            assert(c0 == 0);
            assert(c1 == 1);
            assert(c2 == 2);
            assert(c3 == 3);
            assert(c4 == 4);
            assert(c5 == 5);
            assert(c6 == 6);
            assert(c7 == 7);
        }
    }
    assert(count_obj == 0);

    return TEST::GetInstance().Status().ReturnValue();
}
