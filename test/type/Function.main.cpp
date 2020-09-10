#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/Function.h"

#include <cstdio>

int Foo1()
{
    printf("Foo1()\n");
    return 1;
}

void Foo2(const int& i)
{
    printf("Foo2(i = %d)\n", i);
}

int main()
{
    typedef test::type::Function<int(), &Foo1> Function1;
    Function1 f1;
    printf("ret = %d\n", f1.Call());

    Function1::Pointer();

    typedef test::type::Function<decltype(Foo2), &Foo2> Function2;
    Function2 f2;
    f2.Call(4);
}

