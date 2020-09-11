#include "test/Variable.h"
#include "test/var/type/Value.h"
#include "test/type/Value.h"

#include <iostream>

int main()
{
    test::Variable<test::type::Value<int, 4>> var1;
    std::cout << "val : " << var1.Get().Get() << std::endl;
    test::Variable<int, test::type::Value<int, 6>> var2;
    test::Variable<test::type::Value<int, 1>, int,
        test::type::Value<int, 4>, char> var3;
}

