#include "test/msg/fmt/param/Precision.h"

#include <cstdio>
#include <cassert>
#include <cstddef>
#include <cstdarg>
#include <utility>

template<typename T>
std::size_t Load(T& obj, std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto index = obj.VLoad(size, 0, args);
    va_end(args);
    return index;
}

int main()
{
using namespace test::msg::fmt::param;

    Precision<char> prec1;
    assert(prec1.GetValue() == 0);
    assert(prec1.IsSet() == false);
    
    auto index = prec1.Load(1, 30);
    assert(index == 1);
    assert(prec1.GetValue() == 30);
    assert(prec1.IsSet() == true);

    index = Load(prec1, 1, 60);
    assert(index == 0);
    assert(prec1.GetValue() != 60);
    assert(prec1.GetValue() == 30);
    assert(prec1.IsSet() == true);

    prec1.Unset();
    assert(prec1.GetValue() == 0);
    assert(prec1.IsSet() == false);
    
    index = Load(prec1, 1, 60);
    assert(prec1.GetValue() == 60);
    assert(prec1.IsSet() == true);

    Precision<char> prec2;
    index = Load(prec2, 1, 60);
    assert(index == 1);
    assert(prec2.GetValue() == 60);
    assert(prec2.IsSet() == true);

    Precision<char> prec3;
    index = prec3.Load(3, 120, 60, 30);
    assert(index == 1);
    assert(prec3.GetValue() == 120);
    assert(prec3.IsSet() == true);

    Precision<char> prec4{240};

    index = prec4.Load(3, 120, 60, 30);
    assert(index == 0);
    assert(prec4.GetValue() == 240);
    assert(prec4.IsSet() == true);

    Precision<char> prec5{prec4};
    assert(prec5.GetValue() == 240);
    assert(prec5.IsSet() == true);

    index = prec5.Load(1, 120);
    assert(index == 0);
    assert(prec5.GetValue() == 240);
    assert(prec5.IsSet() == true);

    Precision<char> prec6{std::move(prec5)};
    assert(prec6.GetValue() == 240);
    assert(prec6.IsSet() == true);

    index = prec6.Load(1, 120);
    assert(index == 0);
    assert(prec6.GetValue() == 240);
    assert(prec6.IsSet() == true);
    
    assert(prec5.GetValue() == 240);
    assert(prec5.IsSet() == true);

    Precision<char> prec7;
    assert(prec7.GetValue() == 0);
    assert(prec7.IsSet() == false);

    prec7 = prec4;
    assert(prec7.GetValue() == 240);
    assert(prec7.IsSet() == true);

    index = prec7.Load(1, 120);
    assert(index == 0);
    assert(prec7.GetValue() == 240);
    assert(prec7.IsSet() == true);

    Precision<char> prec8;
    assert(prec8.GetValue() == 0);
    assert(prec8.IsSet() == false);

    prec8 = std::move(prec7);
    assert(prec8.GetValue() == 240);
    assert(prec8.IsSet() == true);

    index = prec8.Load(1, 120);
    assert(index == 0);
    assert(prec8.GetValue() == 240);
    assert(prec8.IsSet() == true);

    assert(prec7.GetValue() == 240);
    assert(prec7.IsSet() == true);

    Precision<char> prec9{10};
    assert(prec9.GetValue() == 10);
    assert(prec9.IsSet() == true);
    
    index = prec9.Load(1, 30);
    assert(index == 0);
    assert(prec9.GetValue() == 10);
    assert(prec9.IsSet() == true);
    
    prec9.Unset();
    assert(prec9.GetValue() == 10);
    assert(prec9.IsSet() == true);

    return 1;
}