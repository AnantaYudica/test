#include "test/var/Element.h"
#include "test/Variable.h"

#include <iostream>
#include <typeinfo>


int main()
{
    typedef test::Variable<int, char, float> Var1;
    std::cout << typeid(test::var::Element<0, 
        Var1>::Type).name() << std::endl;
    std::cout << typeid(test::var::Element<1, 
        Var1>::Type).name() << std::endl;
    std::cout << typeid(test::var::Element<2, 
        Var1>::Type).name() << std::endl;
}
