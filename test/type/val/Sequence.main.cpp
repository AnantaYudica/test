#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/val/Sequence.h"

#include <cstdio>

int main()
{
    typedef test::type::val::Sequence<int> ValSeqInt0;
    printf("Size : %d\n", ValSeqInt0::Size);
    typedef test::type::val::Sequence<int, 4> ValSeqInt1;
    ValSeqInt1 i1;
    printf("[0] : %d\n", ValSeqInt1{}.At<0>());
    printf("[0] : %d\n", i1.At<0>());
    printf("Size : %d\n", ValSeqInt1::Size);
    typedef test::type::val::Sequence<int, 4, 6, 11, 14> ValSeqInt4;
    ValSeqInt4 i4;
    printf("[0] : %d\n", ValSeqInt4{}.At<0>());
    printf("[1] : %d\n", ValSeqInt4{}.At<1>());
    printf("[2] : %d\n", ValSeqInt4{}.At<2>());
    printf("[3] : %d\n", ValSeqInt4{}.At<3>());
    printf("[0] : %d\n", i4.At<0>());
    printf("[1] : %d\n", i4.At<1>());
    printf("[2] : %d\n", i4.At<2>());
    printf("[3] : %d\n", i4.At<3>());
    printf("Size : %d\n", ValSeqInt4::Size);
}
