#include "test/Variable.h"
#include "test/var/Value.h"
#include "test/Value.h"

#include <iostream>

int main()
{
    test::Variable<test::Value<int>> var1(4);
    std::cout << "value : " << var1.Get().Get() << std::endl;
    test::Variable<int, test::Value<int>> var2(6);
    test::Variable<test::Value<int>, int,
        test::Value<int>, char> var3(4, 6);
}
