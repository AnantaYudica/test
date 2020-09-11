#include "test/Variable.h"

#include <iostream>

int main()
{
    test::Variable<> var1;
    test::Variable<int> var2;
    test::Variable<int, char> var3;
    test::Variable<int, char, float> var4;
}

