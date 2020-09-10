#include "Test.h"

#include "test/type/param/Size.h"

#include <cstdio>

typedef test::type::Parameter<int, float, char, int, double, short> P1;

template<typename...>
struct Param1{};

int main()
{
    printf("P1 Size : %zd\n", test::type::param::Size<P1>::Value);
    printf("Param1<int, int, char> : %zd\n", test::type::param::
        Size<Param1<int, int, char>>::Value);

}

