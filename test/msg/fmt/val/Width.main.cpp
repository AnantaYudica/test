#include "test/msg/fmt/val/Width.h"

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
    using namespace test::msg::fmt::val;

    Width<char> wd1;
    assert(wd1.GetValue() == 0);
    assert(wd1.IsSet() == false);
    
    auto index = wd1.Load(1, 30);
    assert(index == 1);
    assert(wd1.GetValue() == 30);
    assert(wd1.IsSet() == true);

    index = Load(wd1, 1, 60);
    assert(index == 0);
    assert(wd1.GetValue() != 60);
    assert(wd1.GetValue() == 30);
    assert(wd1.IsSet() == true);

    wd1.Unset();
    assert(wd1.GetValue() == 0);
    assert(wd1.IsSet() == false);
    
    index = Load(wd1, 1, 60);
    assert(wd1.GetValue() == 60);
    assert(wd1.IsSet() == true);

    Width<char> wd2;
    index = Load(wd2, 1, 60);
    assert(index == 1);
    assert(wd2.GetValue() == 60);
    assert(wd2.IsSet() == true);

    Width<char> wd3;
    index = wd3.Load(3, 120, 60, 30);
    assert(index == 1);
    assert(wd3.GetValue() == 120);
    assert(wd3.IsSet() == true);

    Width<char> wd4{240};

    index = wd4.Load(3, 120, 60, 30);
    assert(index == 0);
    assert(wd4.GetValue() == 240);
    assert(wd4.IsSet() == true);

    Width<char> wd5{wd4};
    assert(wd5.GetValue() == 240);
    assert(wd5.IsSet() == true);

    index = wd5.Load(1, 120);
    assert(index == 0);
    assert(wd5.GetValue() == 240);
    assert(wd5.IsSet() == true);

    Width<char> wd6{std::move(wd5)};
    assert(wd6.GetValue() == 240);
    assert(wd6.IsSet() == true);

    index = wd6.Load(1, 120);
    assert(index == 0);
    assert(wd6.GetValue() == 240);
    assert(wd6.IsSet() == true);
    
    assert(wd5.GetValue() == 240);
    assert(wd5.IsSet() == true);

    Width<char> wd7;
    assert(wd7.GetValue() == 0);
    assert(wd7.IsSet() == false);

    wd7 = wd4;
    assert(wd7.GetValue() == 240);
    assert(wd7.IsSet() == true);

    index = wd7.Load(1, 120);
    assert(index == 0);
    assert(wd7.GetValue() == 240);
    assert(wd7.IsSet() == true);

    Width<char> wd8;
    assert(wd8.GetValue() == 0);
    assert(wd8.IsSet() == false);

    wd8 = std::move(wd7);
    assert(wd8.GetValue() == 240);
    assert(wd8.IsSet() == true);

    index = wd8.Load(1, 120);
    assert(index == 0);
    assert(wd8.GetValue() == 240);
    assert(wd8.IsSet() == true);

    assert(wd7.GetValue() == 240);
    assert(wd7.IsSet() == true);

    Width<char> wd9{10};
    assert(wd9.GetValue() == 10);
    assert(wd9.IsSet() == true);
    
    index = wd9.Load(1, 30);
    assert(index == 0);
    assert(wd9.GetValue() == 10);
    assert(wd9.IsSet() == true);
    
    wd9.Unset();
    assert(wd9.GetValue() == 10);
    assert(wd9.IsSet() == true);
    

    return 0;
}