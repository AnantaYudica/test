#include "test/Variable.h"
#include "test/var/At.h"
#include "test/var/type/Value.h"
#include "test/var/type/val/Sequence.h"
#include "test/var/Value.h"
#include "test/var/val/Sequence.h"
#include "test/var/val/Parameter.h"

#include <iostream>
#include <typeinfo>


int main()
{
    typedef test::Variable<
        int, 
        test::type::Value<int, 4>,
        test::type::val::Sequence<int, 1, 2, 3, 4>,
        test::val::Parameter<int, int, int>,
        test::Value<int>,
        test::val::Sequence<int,2>> Var1;

    Var1 var1(4, 6, 14, 1, 4, 11);
    std::cout << "var::At<1, Var1> Variable : " << 
        test::var::At<1>(var1).Get().Get() << std::endl;

    std::cout << "var::At<2, Var1> : { " << std::endl;
    std::cout << test::var::At<2>(var1).Get().At<0>() << std::endl;
    std::cout << test::var::At<2>(var1).Get().At<1>() << std::endl;
    std::cout << test::var::At<2>(var1).Get().At<2>() << std::endl;
    std::cout << test::var::At<2>(var1).Get().At<3>() <<
        "}" << std::endl;
    
    std::cout << "var::At<3, Var1> : { " << std::endl;
    std::cout << test::var::At<3>(var1).Get().At<0>() << std::endl;
    std::cout << test::var::At<3>(var1).Get().At<1>() << std::endl;
    std::cout << test::var::At<3>(var1).Get().At<2>() <<
        "}" << std::endl;
    
    std::cout << "var::At<4, Var1> Variable : " << 
        test::var::At<4>(var1).Get().Get() << std::endl;
    
    std::cout << "var::At<5, Var1> : { " << std::endl;
    std::cout << test::var::At<5>(var1).Get().At<0>() << std::endl;
    std::cout << test::var::At<5>(var1).Get().At<1>() <<
        "}" << std::endl;

}