#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_STRUCTURE_DLEVEL 0x7f

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/arg/Structure.h"

#include <cassert>
#include <climits>
#include <cfloat>

int main()
{
    {
        test::arg::Structure s1{sizeof(int)};

        assert(s1.Size() == 1);
        assert(s1.AllocationSize() == sizeof(int));

        assert(s1.AllocationSize(0) == sizeof(int));
        assert(s1.AllocationSize(1) == 0);

        s1.template Set<int>(0, 234);
        auto v0 = s1.template Get<int>(0);

        assert(*v0 == 234);
    }
    {
        test::arg::Structure s1{sizeof(int), sizeof(int), sizeof(int),
            sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int),
            sizeof(int), sizeof(int)};

        assert(s1.Size() == 10);
        assert(s1.AllocationSize() == sizeof(int) * 10);
        assert(s1.AllocationSize(0) == sizeof(int));
        assert(s1.AllocationSize(1) == sizeof(int));
        assert(s1.AllocationSize(2) == sizeof(int));
        assert(s1.AllocationSize(3) == sizeof(int));
        assert(s1.AllocationSize(4) == sizeof(int));
        assert(s1.AllocationSize(5) == sizeof(int));
        assert(s1.AllocationSize(6) == sizeof(int));
        assert(s1.AllocationSize(7) == sizeof(int));
        assert(s1.AllocationSize(8) == sizeof(int));
        assert(s1.AllocationSize(9) == sizeof(int));
        assert(s1.AllocationSize(10) == 0);

        s1.template Set<int>(0, 234);
        s1.template Set<int>(1, 567);
        s1.template Set<int>(2, 890);
        s1.template Set<int>(3, 123);
        s1.template Set<int>(4, 456);
        s1.template Set<int>(5, 789);
        s1.template Set<int>(6, 12);
        s1.template Set<int>(7, 345);
        s1.template Set<int>(8, 678);
        s1.template Set<int>(9, 901);
        auto v0 = s1.template Get<int>(0);
        auto v1 = s1.template Get<int>(1);
        auto v2 = s1.template Get<int>(2);
        auto v3 = s1.template Get<int>(3);
        auto v4 = s1.template Get<int>(4);
        auto v5 = s1.template Get<int>(5);
        auto v6 = s1.template Get<int>(6);
        auto v7 = s1.template Get<int>(7);
        auto v8 = s1.template Get<int>(8);
        auto v9 = s1.template Get<int>(9);
        
        assert(*v0 == 234);
        assert(*v1 == 567);
        assert(*v2 == 890);
        assert(*v3 == 123);
        assert(*v4 == 456);
        assert(*v5 == 789);
        assert(*v6 == 12);
        assert(*v7 == 345);
        assert(*v8 == 678);
        assert(*v9 == 901);
    }
    {
        const std::size_t size_alloc = sizeof(int) +
            sizeof(char) + sizeof(long long) + sizeof(char) +
            sizeof(long double) + sizeof(short) + sizeof(int*);
        test::arg::Structure s1{sizeof(int), sizeof(char), sizeof(long long), 
            sizeof(char), sizeof(long double), sizeof(short), sizeof(int*)};
        int p0 = INT_MIN;
        
        assert(s1.Size() == 7);
        assert(s1.AllocationSize() == size_alloc);
        assert(s1.AllocationSize(0) == sizeof(int));
        assert(s1.AllocationSize(1) == sizeof(char));
        assert(s1.AllocationSize(2) == sizeof(long long));
        assert(s1.AllocationSize(3) == sizeof(char));
        assert(s1.AllocationSize(4) == sizeof(long double));
        assert(s1.AllocationSize(5) == sizeof(short));
        assert(s1.AllocationSize(6) == sizeof(int*));
        assert(s1.AllocationSize(7) == 0);

        s1.template Set<int>(0, INT_MAX);
        s1.template Set<char>(1, 'L');
        s1.template Set<long long>(2, LLONG_MAX);
        s1.template Set<char>(3, 'a');
        s1.template Set<long double>(4, LDBL_MIN);
        s1.template Set<short>(5, SHRT_MIN);
        s1.template Set<int*>(6, &p0);
        
        auto v0 = s1.template Get<int>(0);
        auto v1 = s1.template Get<char>(1);
        auto v2 = s1.template Get<long long>(2);
        auto v3 = s1.template Get<char>(3);
        auto v4 = s1.template Get<long double>(4);
        auto v5 = s1.template Get<short>(5);
        auto v6 = s1.template Get<int*>(6);
        assert(*v0 == INT_MAX);
        assert(*v1 == 'L');
        assert(*v2 == LLONG_MAX);
        assert(*v3 == 'a');
        assert(*v4 == LDBL_MIN);
        assert(*v5 == SHRT_MIN);
        assert(*v6 == &p0);

        test::arg::Structure s2{s1};
        {
            assert(s2.Size() == 7);
            assert(s2.AllocationSize() == size_alloc);
            assert(s2.AllocationSize(0) == sizeof(int));
            assert(s2.AllocationSize(1) == sizeof(char));
            assert(s2.AllocationSize(2) == sizeof(long long));
            assert(s2.AllocationSize(3) == sizeof(char));
            assert(s2.AllocationSize(4) == sizeof(long double));
            assert(s2.AllocationSize(5) == sizeof(short));
            assert(s2.AllocationSize(6) == sizeof(int*));
            assert(s2.AllocationSize(7) == 0);
            
            auto v2_0 = s2.template Get<int>(0);
            auto v2_1 = s2.template Get<char>(1);
            auto v2_2 = s2.template Get<long long>(2);
            auto v2_3 = s2.template Get<char>(3);
            auto v2_4 = s2.template Get<long double>(4);
            auto v2_5 = s2.template Get<short>(5);
            auto v2_6 = s2.template Get<int*>(6);
            assert(*v2_0 == INT_MAX);
            assert(*v2_1 == 'L');
            assert(*v2_2 == LLONG_MAX);
            assert(*v2_3 == 'a');
            assert(*v2_4 == LDBL_MIN);
            assert(*v2_5 == SHRT_MIN);
            assert(*v2_6 == &p0);
        }
        test::arg::Structure s3{std::move(s2)};
        {
            assert(s3.Size() == 7);
            assert(s3.AllocationSize() == size_alloc);
            assert(s3.AllocationSize(0) == sizeof(int));
            assert(s3.AllocationSize(1) == sizeof(char));
            assert(s3.AllocationSize(2) == sizeof(long long));
            assert(s3.AllocationSize(3) == sizeof(char));
            assert(s3.AllocationSize(4) == sizeof(long double));
            assert(s3.AllocationSize(5) == sizeof(short));
            assert(s3.AllocationSize(6) == sizeof(int*));
            assert(s3.AllocationSize(7) == 0);
            
            auto v2_0 = s3.template Get<int>(0);
            auto v2_1 = s3.template Get<char>(1);
            auto v2_2 = s3.template Get<long long>(2);
            auto v2_3 = s3.template Get<char>(3);
            auto v2_4 = s3.template Get<long double>(4);
            auto v2_5 = s3.template Get<short>(5);
            auto v2_6 = s3.template Get<int*>(6);
            assert(*v2_0 == INT_MAX);
            assert(*v2_1 == 'L');
            assert(*v2_2 == LLONG_MAX);
            assert(*v2_3 == 'a');
            assert(*v2_4 == LDBL_MIN);
            assert(*v2_5 == SHRT_MIN);
            assert(*v2_6 == &p0);
        }
        {
            assert(s2.Size() == 7);
            assert(s2.AllocationSize() == size_alloc);
            assert(s2.AllocationSize(0) == sizeof(int));
            assert(s2.AllocationSize(1) == sizeof(char));
            assert(s2.AllocationSize(2) == sizeof(long long));
            assert(s2.AllocationSize(3) == sizeof(char));
            assert(s2.AllocationSize(4) == sizeof(long double));
            assert(s2.AllocationSize(5) == sizeof(short));
            assert(s2.AllocationSize(6) == sizeof(int*));
            assert(s2.AllocationSize(7) == 0);
            
            auto v2_0 = s2.template Get<int>(0);
            auto v2_1 = s2.template Get<char>(1);
            auto v2_2 = s2.template Get<long long>(2);
            auto v2_3 = s2.template Get<char>(3);
            auto v2_4 = s2.template Get<long double>(4);
            auto v2_5 = s2.template Get<short>(5);
            auto v2_6 = s2.template Get<int*>(6);
            assert(*v2_0 == INT_MAX);
            assert(*v2_1 == 'L');
            assert(*v2_2 == LLONG_MAX);
            assert(*v2_3 == 'a');
            assert(*v2_4 == LDBL_MIN);
            assert(*v2_5 == SHRT_MIN);
            assert(*v2_6 == &p0);
        }
        test::arg::Structure s4;
        s4 = s3;
        {
            assert(s4.Size() == 7);
            assert(s4.AllocationSize() == size_alloc);
            assert(s4.AllocationSize(0) == sizeof(int));
            assert(s4.AllocationSize(1) == sizeof(char));
            assert(s4.AllocationSize(2) == sizeof(long long));
            assert(s4.AllocationSize(3) == sizeof(char));
            assert(s4.AllocationSize(4) == sizeof(long double));
            assert(s4.AllocationSize(5) == sizeof(short));
            assert(s4.AllocationSize(6) == sizeof(int*));
            assert(s4.AllocationSize(7) == 0);
            
            auto v2_0 = s4.template Get<int>(0);
            auto v2_1 = s4.template Get<char>(1);
            auto v2_2 = s4.template Get<long long>(2);
            auto v2_3 = s4.template Get<char>(3);
            auto v2_4 = s4.template Get<long double>(4);
            auto v2_5 = s4.template Get<short>(5);
            auto v2_6 = s4.template Get<int*>(6);
            assert(*v2_0 == INT_MAX);
            assert(*v2_1 == 'L');
            assert(*v2_2 == LLONG_MAX);
            assert(*v2_3 == 'a');
            assert(*v2_4 == LDBL_MIN);
            assert(*v2_5 == SHRT_MIN);
            assert(*v2_6 == &p0);
        }
        test::arg::Structure s5;
        s5 = std::move(s4);
        {
            assert(s5.Size() == 7);
            assert(s5.AllocationSize() == size_alloc);
            assert(s5.AllocationSize(0) == sizeof(int));
            assert(s5.AllocationSize(1) == sizeof(char));
            assert(s5.AllocationSize(2) == sizeof(long long));
            assert(s5.AllocationSize(3) == sizeof(char));
            assert(s5.AllocationSize(4) == sizeof(long double));
            assert(s5.AllocationSize(5) == sizeof(short));
            assert(s5.AllocationSize(6) == sizeof(int*));
            assert(s5.AllocationSize(7) == 0);
            
            auto v2_0 = s5.template Get<int>(0);
            auto v2_1 = s5.template Get<char>(1);
            auto v2_2 = s5.template Get<long long>(2);
            auto v2_3 = s5.template Get<char>(3);
            auto v2_4 = s5.template Get<long double>(4);
            auto v2_5 = s5.template Get<short>(5);
            auto v2_6 = s5.template Get<int*>(6);
            assert(*v2_0 == INT_MAX);
            assert(*v2_1 == 'L');
            assert(*v2_2 == LLONG_MAX);
            assert(*v2_3 == 'a');
            assert(*v2_4 == LDBL_MIN);
            assert(*v2_5 == SHRT_MIN);
            assert(*v2_6 == &p0);
        }
    }
    return TEST::GetInstance().Status().ReturnValue();
}
