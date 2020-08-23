#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include <cstring>
#include <cassert>

int main()
{
    assert(strcmp(*(test::type::name::Array<int[]>::CStr()), "[]") == 0);
    assert(strcmp(*(test::type::name::Array<int[10]>::CStr()), "[10]") == 0);
    return TEST::GetInstance().Status().Get();
}