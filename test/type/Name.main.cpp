#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/Name.h"

#include <cstdio>

struct A {};

template<>
struct test::type::Name<char>
{
    static test::CString<const char> CStr()
    {
        static char _char[] = "char";
        return {_char};
    }
};

template<>
struct test::type::Name<A>
{
    static test::CString<const char> CStr()
    {
        static char _A[] = "A";
        return {_A};
    }
};

int main()
{
    printf("%s\n", *test::type::Name<char>::CStr());
    printf("%s\n", *test::type::Name<A>::CStr());
}
