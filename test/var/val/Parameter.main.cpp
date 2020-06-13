#include "test/Variable.h"
#include "test/var/val/Parameter.h"
#include "test/val/Parameter.h"

#include <iostream>
#include <typeinfo>

void Print1(int i)
{
    std::cout << "Print1 (i = " << i << ")" << std::endl;
} 

void Print2(int i, char c, float f)
{
    std::cout << "Print1 (i = " << i;
    std::cout << ", c = " << c;
    std::cout << ", f = " << f << ")" << std::endl;
}

int main()
{
    basic::test::Variable<basic::test::val::Parameter<int>> var1(4);
    var1.Get().Fill<void>(&Print1);
    basic::test::Variable<int, basic::test::val::Parameter<int>> var2(6);
    basic::test::Variable<basic::test::val::Parameter<int, char, float>, int,
        basic::test::val::Parameter<int>, char> var3(4, 'a', 3.14f, 14);
    var3.Get().Fill<void>(&Print2);

}
