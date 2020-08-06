#include "test/msg/fmt/val/specifier/print/FloatingPoint.h"
#include "test/msg/fmt/val/specifier/val/FloatingPoint.h"
#include "test/msg/fmt/val/flag/FloatingPoint.h"
#include "test/msg/fmt/val/Width.h"
#include "test/msg/fmt/val/Precision.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <type_traits>

#include <cstdio>

int main()
{
    using namespace test::msg::fmt::val;
    using namespace test::msg::fmt::var;
    specifier::val::FloatingPoint val1{.float_value=3.14f};
    specifier::val::FloatingPoint val2{.double_value=3.14};
    specifier::val::FloatingPoint val3{.long_double_value=3.14};
    Width<char> wd1{14};
    Precision<char> prec1{8};
    {
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{};

                out_cstr1_a.Print("%f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%Lf", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%Lf", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%Lf", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%F", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%F", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%F", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%LF", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%LF", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%LF", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%e", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%e", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%e", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%Le", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%Le", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%Le", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%E", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%E", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%E", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%LE", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%LE", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%LE", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{}};

                out_cstr1_a.Print("%g", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%g", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%g", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%Lg", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%Lg", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%Lg", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%G", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%G", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%G", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%LG", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%LG", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%LG", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%a", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%a", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%a", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%La", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%La", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%La", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}};

                out_cstr1_a.Print("%A", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%A", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%A", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}};

                out_cstr1_a.Print("%LA", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%LA", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%LA", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::Prefix{}
                };

                out_cstr1_a.Print("%#f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#Lf", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#Lf", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#Lf", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#F", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#F", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#F", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#LF", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#LF", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#LF", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#e", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#e", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#e", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#Le", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#Le", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#Le", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#E", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#E", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#E", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#LE", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#LE", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#LE", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#g", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#g", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#g", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#Lg", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#Lg", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#Lg", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#G", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#G", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#G", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#LG", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#LG", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#LG", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#a", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#a", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#a", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#La", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#La", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#La", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#A", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#A", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#A", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}};

                out_cstr1_a.Print("%#LA", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#LA", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#LA", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixPlus{}
                };

                out_cstr1_a.Print("%+f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+Lf", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+Lf", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+Lf", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+F", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+F", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+F", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+LF", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+LF", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+LF", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+e", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+e", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+e", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+Le", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+Le", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+Le", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+E", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+E", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+E", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+LE", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+LE", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+LE", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+g", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+g", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+g", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+Lg", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+Lg", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+Lg", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+G", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+G", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+G", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+LG", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+LG", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+LG", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+a", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+a", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+a", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+La", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+La", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+La", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+A", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+A", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+A", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}};

                out_cstr1_a.Print("%+LA", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+LA", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+LA", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
        
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixSpace{}
                };

                out_cstr1_a.Print("% f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% Lf", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% Lf", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% Lf", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% F", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% F", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% F", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% LF", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% LF", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% LF", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% e", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% e", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% e", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% Le", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% Le", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% Le", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% E", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% E", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% E", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% LE", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% LE", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% LE", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% g", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% g", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% g", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% Lg", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% Lg", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% Lg", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% G", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% G", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% G", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% LG", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% LG", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% LG", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% a", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% a", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% a", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% La", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% La", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% La", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% A", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% A", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% A", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}};

                out_cstr1_a.Print("% LA", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% LA", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% LA", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixZero{}
                };

                out_cstr1_a.Print("%0f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0f", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0f", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0f", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0Lf", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0Lf", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0Lf", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0F", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0F", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0F", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0LF", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0LF", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0LF", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0e", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0e", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0e", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0Le", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0Le", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0Le", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0E", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0E", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0E", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0LE", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0LE", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0LE", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0g", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0g", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0g", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0Lg", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0Lg", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0Lg", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0G", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0G", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0G", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0LG", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0LG", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0LG", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0a", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0a", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0a", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0La", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0La", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0La", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0A", (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0A", val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0A", (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}};

                out_cstr1_a.Print("%0LA", (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0LA", (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0LA", (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
    }

    {
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                        arg::Width{}
                };

                out_cstr1_a.Print("%*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);
             
                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*Lf", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*Lf", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*Lf", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*F", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*F", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*F", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*LF", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*LF", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*LF", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*e", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*e", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*e", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*Le", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*Le", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*Le", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*E", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*E", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*E", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*LE", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*LE", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*LE", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*g", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*g", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*g", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*Lg", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*Lg", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*Lg", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*G", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*G", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*G", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*LG", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*LG", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*LG", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*a", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*a", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*a", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*La", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*La", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*La", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}};

                out_cstr1_a.Print("%*A", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*A", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*A", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}};

                out_cstr1_a.Print("%*LA", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*LA", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*LA", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::Prefix{}, arg::Width{}
                };

                out_cstr1_a.Print("%#*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*Lf", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*Lf", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*Lf", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*F", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*F", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*F", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*LF", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*LF", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*LF", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*e", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*e", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*e", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*Le", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*Le", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*Le", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*E", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*E", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*E", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*LE", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*LE", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*LE", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*g", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*g", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*g", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*Lg", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*Lg", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*Lg", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*G", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*G", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*G", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*LG", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*LG", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*LG", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*a", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*a", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*a", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*La", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*La", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*La", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*A", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*A", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*A", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}};

                out_cstr1_a.Print("%#*LA", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*LA", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*LA", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixPlus{}, arg::Width{}
                };

                out_cstr1_a.Print("%+*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*Lf", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*Lf", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*Lf", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*F", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*F", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*F", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*LF", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*LF", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*LF", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*e", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*e", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*e", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*Le", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*Le", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*Le", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*E", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*E", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*E", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*LE", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*LE", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*LE", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*g", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*g", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*g", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*Lg", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*Lg", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*Lg", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*G", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*G", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*G", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*LG", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*LG", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*LG", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*a", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*a", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*a", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*La", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*La", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*La", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*A", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*A", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*A", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}};

                out_cstr1_a.Print("%+*LA", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*LA", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*LA", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
        
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixSpace{}, arg::Width{}
                };

                out_cstr1_a.Print("% *f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *Lf", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *Lf", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *Lf", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *F", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *F", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *F", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *LF", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *LF", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *LF", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *e", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *e", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *e", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *Le", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *Le", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *Le", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *E", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *E", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *E", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *LE", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *LE", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *LE", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *g", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *g", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *g", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *Lg", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *Lg", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *Lg", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *G", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *G", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *G", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *LG", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *LG", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *LG", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *a", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *a", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *a", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *La", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *La", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *La", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *A", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *A", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *A", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}};

                out_cstr1_a.Print("% *LA", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *LA", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *LA", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixZero{}, arg::Width{}
                };

                out_cstr1_a.Print("%0*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*f", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*f", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*f", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*Lf", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*Lf", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*Lf", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*F", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*F", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*F", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*LF", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*LF", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*LF", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*e", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*e", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*e", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*Le", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*Le", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*Le", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*E", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*E", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*E", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*LE", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*LE", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*LE", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*g", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*g", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*g", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*Lg", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*Lg", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*Lg", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*G", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*G", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*G", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*LG", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*LG", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*LG", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*a", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*a", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*a", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*La", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*La", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*La", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*A", wd1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*A", wd1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*A", wd1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}};

                out_cstr1_a.Print("%0*LA", wd1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*LA", wd1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*LA", wd1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
    }

    {
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::Precision{}
                };

                out_cstr1_a.Print("%.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*Lf", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*Lf", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*Lf", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*F", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*F", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*F", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*LF", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*LF", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*LF", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*e", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*e", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*e", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*Le", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*Le", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*Le", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*E", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*E", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*E", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*LE", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*LE", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*LE", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*g", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*g", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*g", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*Lg", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*Lg", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*Lg", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*G", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*G", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*G", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*LG", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*LG", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*LG", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*a", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*a", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*a", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*La", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*La", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*La", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*A", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*A", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*A", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Precision{}};

                out_cstr1_a.Print("%.*LA", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%.*LA", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%.*LA", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::Prefix{}, arg::Precision{}
                };

                out_cstr1_a.Print("%#.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*Lf", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*Lf", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*Lf", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*F", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*F", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*F", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*LF", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*LF", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*LF", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*e", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*e", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*e", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*Le", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*Le", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*Le", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*E", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*E", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*E", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*LE", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*LE", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*LE", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*g", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*g", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*g", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*Lg", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*Lg", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*Lg", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*G", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*G", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*G", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*LG", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*LG", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*LG", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*a", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*a", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*a", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*La", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*La", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*La", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*A", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*A", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*A", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Precision{}};

                out_cstr1_a.Print("%#.*LA", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#.*LA", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#.*LA", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixPlus{}, arg::Precision{}
                };

                out_cstr1_a.Print("%+.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*Lf", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*Lf", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*Lf", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*F", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*F", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*F", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*LF", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*LF", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*LF", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*e", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*e", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*e", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*Le", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*Le", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*Le", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*E", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*E", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*E", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*LE", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*LE", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*LE", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*g", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*g", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*g", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*Lg", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*Lg", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*Lg", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*G", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*G", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*G", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*LG", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*LG", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*LG", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*a", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*a", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*a", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*La", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*La", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*La", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*A", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*A", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*A", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Precision{}};

                out_cstr1_a.Print("%+.*LA", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+.*LA", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+.*LA", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
        
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixSpace{}, arg::Precision{}
                };

                out_cstr1_a.Print("% .*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*Lf", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*Lf", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*Lf", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*F", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*F", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*F", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*LF", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*LF", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*LF", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*e", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*e", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*e", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*Le", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*Le", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*Le", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*E", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*E", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*E", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*LE", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*LE", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*LE", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*g", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*g", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*g", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*Lg", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*Lg", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*Lg", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*G", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*G", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*G", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*LG", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*LG", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*LG", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*a", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*a", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*a", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*La", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*La", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*La", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*A", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*A", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*A", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Precision{}};

                out_cstr1_a.Print("% .*LA", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% .*LA", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% .*LA", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixZero{}, arg::Precision{}
                };

                out_cstr1_a.Print("%0.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*f", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*f", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*f", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*Lf", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*Lf", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*Lf", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*F", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*F", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*F", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*LF", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*LF", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*LF", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*e", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*e", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*e", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*Le", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*Le", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*Le", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*E", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*E", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*E", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*LE", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*LE", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*LE", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*g", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*g", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*g", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*Lg", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*Lg", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*Lg", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*G", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*G", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*G", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*LG", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*LG", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*LG", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*a", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*a", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*a", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*La", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*La", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*La", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*A", prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*A", prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*A", prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Precision{}};

                out_cstr1_a.Print("%0.*LA", prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0.*LA", prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0.*LA", prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
    }

    
    {
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::Width{}, arg::Precision{}
                };

                out_cstr1_a.Print("%*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*F", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*e", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*E", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*g", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*G", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*a", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*A", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}
                };

                out_cstr1_a.Print("%#*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*F", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*e", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*E", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*g", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*G", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*a", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*A", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::Prefix{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%#*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%#*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%#*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}
                };

                out_cstr1_a.Print("%+*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*F", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*e", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*E", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*g", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*G", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*a", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*A", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixPlus{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%+*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%+*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%+*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
        
        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}
                };

                out_cstr1_a.Print("% *.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*F", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*e", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*E", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*g", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*G", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*a", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*A", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixSpace{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("% *.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("% *.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("% *.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }

        {
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}
                };

                out_cstr1_a.Print("%0*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*f", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*f", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*Lf", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*F", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*F", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*LF", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*e", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*e", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*Le", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*E", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*E", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*LE", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{}, 
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*g", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*g", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*Lg", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*G", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*G", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Decimal{}, arg::Fixed{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*LG", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*a", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*a", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Lower{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*La", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
            
            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*A", wd1.GetValue(), prec1.GetValue(),
                    val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*A", wd1.GetValue(), prec1.GetValue(),
                    (double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }

            {
                test::out::CString<char> out_cstr1_a, out_cstr1_b;
                test::out::CString<char> out_cstr2_a, out_cstr2_b;
                test::out::CString<char> out_cstr3_a, out_cstr3_b;
                constexpr flag::FloatingPoint ff1{arg::Upper{},
                    arg::Hexadecimal{}, arg::Exponent{},
                    arg::Define<long double>{},
                    arg::PrefixZero{}, arg::Width{}, 
                    arg::Precision{}};

                out_cstr1_a.Print("%0*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val1.float_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr1_b, wd1, prec1, val1);

                out_cstr2_a.Print("%0*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val2.double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr2_b, wd1, prec1, val2);
                
                out_cstr3_a.Print("%0*.*LA", wd1.GetValue(), prec1.GetValue(),
                    (long double)val3.long_double_value);
                specifier::print::FloatingPoint<char, ff1.GetValue()>::
                    Print(out_cstr3_b, wd1, prec1, val3);

                assert(out_cstr1_a.Size() == out_cstr1_b.Size());
                assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                    out_cstr1_b.Size()) == 0);
                assert(out_cstr2_a.Size() == out_cstr2_b.Size());
                assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
                    out_cstr2_b.Size()) == 0);
                assert(out_cstr3_a.Size() == out_cstr3_b.Size());
                assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
                    out_cstr3_b.Size()) == 0);
            }
        }
    }


    return 1;
}