#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Qualifier.h"

#include <cassert>
#include <cstring>

int main()
{
    assert(strcmp(*(test::type::name::Qualifier<const int>::CStr()), 
        "const") == 0);
    assert(strcmp(*(test::type::name::Qualifier<volatile int>::CStr()), 
        "volatile") == 0);
    assert(strcmp(*(test::type::name::Qualifier<const volatile int>::CStr()), 
        "const volatile") == 0);
    
    return TEST::GetInstance().Status().Get();
}
