#include "test/Variable.h"
#include "test/var/type/Function.h"
#include "test/type/Function.h"

#include <iostream>

void Foo1()
{
    printf("Foo1()\n");
}

int main()
{
    test::Variable<test::type::Function<void(), 
        &Foo1>> var1;
    var1.Get().Call();
    test::Variable<int, test::type::
        Function<void(), &Foo1>> var2;
    test::Variable<test::type::Function<void(), &Foo1>, int,
        test::type::Function<void(), &Foo1>, char> var3;
}
