#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/cstr/Format.h"

#include <cstdio>

int main()
{
    auto ch1 = test::cstr::Format(10, "%d", 1234);
    printf("%s\n", *ch1);
    auto ch2 = test::cstr::Format(2, "%d", 1234);
    printf("%s\n", *ch2);
    auto ch3 = test::cstr::Format(0, "%d", 1234);
    printf("%s\n", *ch3);
    int i = 14;
    auto ch4 = test::cstr::Format(10, "%s = %d", "int i", i);
    printf("%s\n", *ch4);
}
