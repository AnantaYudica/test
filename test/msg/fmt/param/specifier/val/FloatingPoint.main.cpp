#include "test/msg/fmt/param/specifier/val/FloatingPoint.h"

#include <cassert>

int main()
{
    using namespace test::msg::fmt::param::specifier::val;
    float pi_f = 3.14F;
    double pi_d = pi_f;
    long double pi_ld = pi_d;
    
    FloatingPoint ff1{0};
    ff1.float_value = pi_f;
    assert(FloatingPoint::GetValue<float>(ff1) == pi_f);
    assert(FloatingPoint::GetValue<double>(ff1) == pi_d);
    assert(FloatingPoint::GetValue<long double>(ff1) == pi_ld);

    FloatingPoint ff2{0};
    ff2.double_value = pi_d;
    assert(FloatingPoint::GetValue<float>(ff2) == pi_f);
    assert(FloatingPoint::GetValue<double>(ff2) == pi_d);
    assert(FloatingPoint::GetValue<long double>(ff2) == pi_ld);

    FloatingPoint ff3{0};
    ff3.long_double_value = pi_ld;
    assert(FloatingPoint::GetValue<float>(ff3) == pi_f);
    assert(FloatingPoint::GetValue<double>(ff3) == pi_d);
    assert(FloatingPoint::GetValue<long double>(ff3) == pi_ld);
    
    return 1;
}