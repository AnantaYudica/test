#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/Value.h"

#include <cstdio>

int main()
{
    typedef test::type::Value<int, 4> ValueInt4;
    ValueInt4 i1;

    printf("%d\n", ValueInt4{}.Get());
}
