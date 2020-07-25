#include "test/msg/fmt/param/specifier/FloatingPoint.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <cstdarg>

template<typename T>
std::size_t Load(T& obj, std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto ret = obj.VLoad(size, 0, args);
    va_end(args);
    return ret;
}

int main()
{
    using namespace test::msg::fmt::param::specifier;
    using namespace test::msg::fmt::param;
    const float float_val1 = 2.22f, float_val2 = 8.88f;
    const double double_val1 = 34.567, double_val2 = 345.67;
    const long double l_double_val1 = 0.000012345L,
        l_double_val2 = 2345.00001L;
    const int wd1 = 10, wd2 = 14;
    const int pres1 = 8, pres2 = 15;
    {
        FloatingPoint<char> ff1;
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        test::out::CString<char> out_cstr3_a, out_cstr3_b;

        assert(ff1.IsSet() == false);
        assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
        assert(val::FloatingPoint::CastTo<double>(ff1.GetValue()) == 0.0);
        printf("CK2");
        assert(val::FloatingPoint::CastTo<long double>(ff1.GetValue())== 0.0L);
        assert(ff1.GetWidth() == 0);
        assert(ff1.GetPrecision() == 0);
        assert(ff1.GetFlag() == flag::FloatingPoint::ldf_double_format);
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

        auto len_a = out_cstr1_a.Print("%f", 
            val::FloatingPoint::CastTo<double>(ff1.GetValue()));
        auto len_b = ff1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(ff1.IsGood() == false);
        assert(ff1.IsBad() == true);
        assert(ff1.GetBadCode() == 
            FloatingPoint<char>::StatusType::value_not_set);

        auto len = ff1.Load(1, 3.14);
        assert(len == 1);
        assert(ff1.IsSet() == true);
        printf("CK : %4.4f\n", ff1.GetValue().double_value);
        printf("CK %4.4f\n", val::FloatingPoint::CastTo<double>(ff1.GetValue()));
        assert(val::FloatingPoint::CastTo<double>(ff1.GetValue()) == 3.14);
        assert(ff1.GetWidth() == 0);
        assert(ff1.GetPrecision() == 0);
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

        len_a = out_cstr2_a.Print("%f", 
            val::FloatingPoint::CastTo<double>(ff1.GetValue()));
        len_b = ff1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

        ff1.Reset();
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

        len = ff1.Load(1, 6.28);
        assert(len == 1);
        assert(ff1.IsSet() == true);
        assert(val::FloatingPoint::CastTo<double>(ff1.GetValue()) == 6.28);
        assert(ff1.GetWidth() == 0);
        assert(ff1.GetPrecision() == 0);
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

        len = Load(ff1, 1, 3.14);
        assert(len == 0);
        assert(ff1.IsSet() == true);
        assert(val::FloatingPoint::CastTo<double>(ff1.GetValue()) == 6.28);
        assert(ff1.GetWidth() == 0);
        assert(ff1.GetPrecision() == 0);
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

        len_a = out_cstr3_a.Print("%f", 
            val::FloatingPoint::CastTo<double>(ff1.GetValue()));
        len_b = ff1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(ff1.IsGood() == true);
        assert(ff1.IsBad() == false);
        assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
    }

    /////
    {
        FloatingPoint<char> ff1{flag::arg::Width{}};
        FloatingPoint<char> ff2{flag::arg::Width{}};
        FloatingPoint<char> ff3{flag::arg::Width{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{}};
        FloatingPoint<char> ff2{flag::arg::Precision{}};
        FloatingPoint<char> ff3{flag::arg::Precision{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{}, flag::arg::Precision{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, flag::arg::Precision{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, flag::arg::Precision{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{pres1}};
        FloatingPoint<char> ff2{flag::arg::Precision{pres1}};
        FloatingPoint<char> ff3{flag::arg::Precision{pres1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, flag::arg::Precision{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, flag::arg::Precision{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, flag::arg::Precision{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Precision{pres1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    //////
    {
        FloatingPoint<char> ff1{flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Precision{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{pres1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Precision{pres1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Precision{pres1}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    ///////
    {
        FloatingPoint<char> ff1{flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Precision{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{pres1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Precision{pres1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Precision{pres1}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                (double)l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    /////
    {
        FloatingPoint<char> ff1{flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%Lf%Lf%Lf", 
                val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double)float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%Lf%Lf%Lf", 
                val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                wd2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                pres2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                0, 0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, (long double) float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, (long double) double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, (long double) float_val2);
            assert(len == 3);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, (long double) double_val2);
            assert(len == 3);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, l_double_val2);
            assert(len == 3);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd2, pres2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                wd1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                wd1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Precision{pres1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Precision{pres1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Precision{pres1}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                0, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 0.0f);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                0.0);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val2);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    /////
    {
        FloatingPoint<char> ff1{float_val1};
        FloatingPoint<char> ff2{double_val1};
        FloatingPoint<char> ff3{l_double_val1};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    /////
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, flag::arg::Precision{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, flag::arg::Precision{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, flag::arg::Precision{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{pres1}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{pres1}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{pres1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, flag::arg::Precision{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    //////
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<float>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    ///////
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%f%f%f", 
                val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, (double)l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*f%*f%*f", 
                wd1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*f%.*f%.*f", 
                pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, 0, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                0, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, (double)l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, (double)l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*f%*.*f%*.*f", 
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    /////
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%Lf%Lf%Lf", 
                val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double)float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%Lf%Lf%Lf", 
                val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                wd2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                pres2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                pres2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                pres2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                0, 0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, 0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, 0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(3, wd2, pres2, (long double) float_val2);
            assert(len == 2);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(3, wd2, pres2, (long double) double_val2);
            assert(len == 2);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(3, wd2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd2, pres2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, pres2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::w_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                wd1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*Lf%*Lf%*Lf", 
                wd1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Precision{pres1}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) == 
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%.*Lf%.*Lf%.*Lf", 
                pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, flag::arg::Precision{}, 
            flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == 0);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == 0);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, pres2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres2);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, pres2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres2);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, pres2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres2);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    
    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                0, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == 0);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(2, wd2, (long double) float_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd2);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(2, wd2, (long double) double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd2);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 1);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }

    {
        FloatingPoint<char> ff1{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff2{double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};
        FloatingPoint<char> ff3{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        
        {
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::wp_ldf_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            ff1.Unset();
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) == 
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff2.Unset();
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff3.Unset();
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            auto len = ff1.Load(1, (long double) float_val2);
            assert(len == 0);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff1.GetValue()) ==
                float_val1);
            assert(ff1.GetWidth() == wd1);
            assert(ff1.GetPrecision() == pres1);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) double_val2);
            assert(len == 0);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff2.GetValue()) ==
                double_val1);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(1, l_double_val2);
            assert(len == 0);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val1);
            assert(ff3.GetWidth() == wd1);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            auto len_a = out_cstr1_a.Print("%*.*Lf%*.*Lf%*.*Lf", 
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }
    }
    /////
    {   
        FloatingPoint<char> ff1{flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
        FloatingPoint<char> ff2{flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
        FloatingPoint<char> ff3{flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
        FloatingPoint<char> ff4{flag::arg::Width{wd1}, 
            flag::arg::Precision{}, flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
        FloatingPoint<char> ff5{float_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
        FloatingPoint<char> ff6{double_val1, flag::arg::Width{}, 
            flag::arg::Precision{pres1}, flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
        FloatingPoint<char> ff7{l_double_val1, flag::arg::Width{wd1}, 
            flag::arg::Precision{}, flag::arg::Define<long double>{},
            flag::arg::Prefix{}, flag::arg::Upper{}, flag::arg::Hexadecimal{},
            flag::arg::Exponent{}};
            

        {
            assert(ff1.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff1.GetValue()) == 
                0.0L);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff2.GetValue()) ==
                0.0L);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                0.0L);
            assert(ff3.GetWidth() == 0);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff4.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff4.GetValue()) == 
                0.0L);
            assert(ff4.GetWidth() == wd1);
            assert(ff4.GetPrecision() == 0);
            assert(ff4.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff4.IsGood() == true);
            assert(ff4.IsBad() == false);
            assert(ff4.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff5.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff5.GetValue()) ==
                float_val1);
            assert(ff5.GetWidth() == wd1);
            assert(ff5.GetPrecision() == pres1);
            assert(ff5.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff5.IsGood() == true);
            assert(ff5.IsBad() == false);
            assert(ff5.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff6.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff6.GetValue()) ==
                double_val1);
            assert(ff6.GetWidth() == 0);
            assert(ff6.GetPrecision() == pres1);
            assert(ff6.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff6.IsGood() == true);
            assert(ff6.IsBad() == false);
            assert(ff6.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff7.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff7.GetValue()) ==
                l_double_val1);
            assert(ff7.GetWidth() == wd1);
            assert(ff7.GetPrecision() == 0);
            assert(ff7.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff7.IsGood() == true);
            assert(ff7.IsBad() == false);
            assert(ff7.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff4.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff5.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff6.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff7.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            len_b += ff4.Output(out_cstr1_b);
            len_b += ff5.Output(out_cstr1_b);
            len_b += ff6.Output(out_cstr1_b);
            len_b += ff7.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == false);
                assert(ff1.IsBad() == true);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2.IsGood() == false);
                assert(ff2.IsBad() == true);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3.IsGood() == false);
                assert(ff3.IsBad() == true);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff4.IsGood() == false);
                assert(ff4.IsBad() == true);
                assert(ff4.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff5.IsGood() == true);
                assert(ff5.IsBad() == false);
                assert(ff5.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff6.IsGood() == false);
                assert(ff6.IsBad() == true);
                assert(ff6.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff7.IsGood() == false);
                assert(ff7.IsBad() == true);
                assert(ff7.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        {
            auto len = ff1.Load(1, (long double) l_double_val2);
            assert(len == 1);
            assert(ff1.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff1.GetValue()) ==
                l_double_val2);
            assert(ff1.GetWidth() == 0);
            assert(ff1.GetPrecision() == 0);
            assert(ff1.IsGood() == true);
            assert(ff1.IsBad() == false);
            assert(ff1.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff2.Load(1, (long double) l_double_val2);
            assert(len == 1);
            assert(ff2.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff2.GetValue()) ==
                l_double_val2);
            assert(ff2.GetWidth() == wd1);
            assert(ff2.GetPrecision() == pres1);
            assert(ff2.IsGood() == true);
            assert(ff2.IsBad() == false);
            assert(ff2.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff3.Load(2, wd2, l_double_val2);
            assert(len == 2);
            assert(ff3.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff3.GetValue()) ==
                l_double_val2);
            assert(ff3.GetWidth() == wd2);
            assert(ff3.GetPrecision() == pres1);
            assert(ff3.IsGood() == true);
            assert(ff3.IsBad() == false);
            assert(ff3.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff4.Load(2, pres2, l_double_val2);
            assert(len == 2);
            assert(ff4.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff4.GetValue()) ==
                l_double_val2);
            assert(ff4.GetWidth() == wd1);
            assert(ff4.GetPrecision() == pres2);
            assert(ff4.IsGood() == true);
            assert(ff4.IsBad() == false);
            assert(ff4.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff5.Load(1, (long double )float_val2);
            assert(len == 0);
            assert(ff5.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff5.GetValue()) ==
                float_val1);
            assert(ff5.GetWidth() == wd1);
            assert(ff5.GetPrecision() == pres1);
            assert(ff5.IsGood() == true);
            assert(ff5.IsBad() == false);
            assert(ff5.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff6.Load(1, wd2, (long double)double_val2);
            assert(len == 1);
            assert(ff6.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff6.GetValue()) ==
                double_val1);
            assert(ff6.GetWidth() == wd2);
            assert(ff6.GetPrecision() == pres1);
            printf("%d\n", ff6.GetBadCode());
            assert(ff6.IsGood() == true);
            assert(ff6.IsBad() == false);
            assert(ff6.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            len = ff7.Load(1, pres2, l_double_val2);
            assert(len == 1);
            assert(ff7.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff7.GetValue()) ==
                l_double_val1);
            assert(ff7.GetWidth() == wd1);
            assert(ff7.GetPrecision() == pres2);
            assert(ff7.IsGood() == true);
            assert(ff7.IsBad() == false);
            assert(ff7.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff1.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff3.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff4.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff5.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff6.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff7.GetValue()));
            auto len_b = ff1.Output(out_cstr1_b);
            len_b += ff2.Output(out_cstr1_b);
            len_b += ff3.Output(out_cstr1_b);
            len_b += ff4.Output(out_cstr1_b);
            len_b += ff5.Output(out_cstr1_b);
            len_b += ff6.Output(out_cstr1_b);
            len_b += ff7.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1.IsGood() == true);
                assert(ff1.IsBad() == false);
                assert(ff1.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff2.IsGood() == true);
                assert(ff2.IsBad() == false);
                assert(ff2.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff3.IsGood() == true);
                assert(ff3.IsBad() == false);
                assert(ff3.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff4.IsGood() == true);
                assert(ff4.IsBad() == false);
                assert(ff4.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff5.IsGood() == true);
                assert(ff5.IsBad() == false);
                assert(ff5.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff6.IsGood() == true);
                assert(ff6.IsBad() == false);
                assert(ff6.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff7.IsGood() == true);
                assert(ff7.IsBad() == false);
                assert(ff7.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }

        FloatingPoint<char> ff8{ff1};
        FloatingPoint<char> ff9{ff2};
        FloatingPoint<char> ff10{ff3};
        FloatingPoint<char> ff11{ff4};
        FloatingPoint<char> ff12{ff5};
        FloatingPoint<char> ff13{ff6};
        FloatingPoint<char> ff14{ff7};

        {
            assert(ff8.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff8.GetValue()) ==
                l_double_val2);
            assert(ff8.GetWidth() == 0);
            assert(ff8.GetPrecision() == 0);
            assert(ff8.IsGood() == true);
            assert(ff8.IsBad() == false);
            assert(ff8.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff9.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff9.GetValue()) ==
                l_double_val2);
            assert(ff9.GetWidth() == wd1);
            assert(ff9.GetPrecision() == pres1);
            assert(ff9.IsGood() == true);
            assert(ff9.IsBad() == false);
            assert(ff9.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff10.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff10.GetValue()) ==
                l_double_val2);
            assert(ff10.GetWidth() == wd2);
            assert(ff10.GetPrecision() == pres1);
            assert(ff10.IsGood() == true);
            assert(ff10.IsBad() == false);
            assert(ff10.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff11.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff11.GetValue()) ==
                l_double_val2);
            assert(ff11.GetWidth() == wd1);
            assert(ff11.GetPrecision() == pres2);
            assert(ff11.IsGood() == true);
            assert(ff11.IsBad() == false);
            assert(ff11.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff12.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff12.GetValue()) ==
                float_val1);
            assert(ff12.GetWidth() == wd1);
            assert(ff12.GetPrecision() == pres1);
            assert(ff12.IsGood() == true);
            assert(ff12.IsBad() == false);
            assert(ff12.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff13.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff13.GetValue()) ==
                double_val1);
            assert(ff13.GetWidth() == wd2);
            assert(ff13.GetPrecision() == pres1);
            printf("%d\n", ff13.GetBadCode());
            assert(ff13.IsGood() == true);
            assert(ff13.IsBad() == false);
            assert(ff13.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff14.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff14.GetValue()) ==
                l_double_val1);
            assert(ff14.GetWidth() == wd1);
            assert(ff14.GetPrecision() == pres2);
            assert(ff14.IsGood() == true);
            assert(ff14.IsBad() == false);
            assert(ff14.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff8.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff9.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff10.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff11.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff12.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff13.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff14.GetValue()));
            auto len_b = ff8.Output(out_cstr1_b);
            len_b += ff9.Output(out_cstr1_b);
            len_b += ff10.Output(out_cstr1_b);
            len_b += ff11.Output(out_cstr1_b);
            len_b += ff12.Output(out_cstr1_b);
            len_b += ff13.Output(out_cstr1_b);
            len_b += ff14.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff8.IsGood() == true);
                assert(ff8.IsBad() == false);
                assert(ff8.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff9.IsGood() == true);
                assert(ff9.IsBad() == false);
                assert(ff9.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff10.IsGood() == true);
                assert(ff10.IsBad() == false);
                assert(ff10.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff11.IsGood() == true);
                assert(ff11.IsBad() == false);
                assert(ff11.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff12.IsGood() == true);
                assert(ff12.IsBad() == false);
                assert(ff12.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff13.IsGood() == true);
                assert(ff13.IsBad() == false);
                assert(ff13.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff14.IsGood() == true);
                assert(ff14.IsBad() == false);
                assert(ff14.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }

        {
            ff8.Unset();
            assert(ff8.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff8.GetValue()) == 
                0.0L);
            assert(ff8.GetWidth() == 0);
            assert(ff8.GetPrecision() == 0);
            assert(ff8.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff8.IsGood() == true);
            assert(ff8.IsBad() == false);
            assert(ff8.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff9.Unset();
            assert(ff9.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff9.GetValue()) ==
                0.0L);
            assert(ff9.GetWidth() == wd1);
            assert(ff9.GetPrecision() == pres1);
            assert(ff9.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff9.IsGood() == true);
            assert(ff9.IsBad() == false);
            assert(ff9.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff10.Unset();
            assert(ff10.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff10.GetValue()) ==
                0.0L);
            assert(ff10.GetWidth() == 0);
            assert(ff10.GetPrecision() == pres1);
            assert(ff10.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff10.IsGood() == true);
            assert(ff10.IsBad() == false);
            assert(ff10.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff11.Unset();
            assert(ff11.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff11.GetValue()) == 
                0.0L);
            assert(ff11.GetWidth() == wd1);
            assert(ff11.GetPrecision() == 0);
            assert(ff11.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff11.IsGood() == true);
            assert(ff11.IsBad() == false);
            assert(ff11.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff12.Unset();
            assert(ff12.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff12.GetValue()) ==
                float_val1);
            assert(ff12.GetWidth() == wd1);
            assert(ff12.GetPrecision() == pres1);
            assert(ff12.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff12.IsGood() == true);
            assert(ff12.IsBad() == false);
            assert(ff12.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff13.Unset();
            assert(ff13.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff13.GetValue()) ==
                double_val1);
            assert(ff13.GetWidth() == 0);
            assert(ff13.GetPrecision() == pres1);
            assert(ff13.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff13.IsGood() == true);
            assert(ff13.IsBad() == false);
            assert(ff13.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff14.Unset();
            assert(ff14.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff14.GetValue()) ==
                l_double_val1);
            assert(ff14.GetWidth() == wd1);
            assert(ff14.GetPrecision() == 0);
            assert(ff14.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff14.IsGood() == true);
            assert(ff14.IsBad() == false);
            assert(ff14.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff8.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff9.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff10.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff11.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff12.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff13.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff14.GetValue()));
            auto len_b = ff8.Output(out_cstr1_b);
            len_b += ff9.Output(out_cstr1_b);
            len_b += ff10.Output(out_cstr1_b);
            len_b += ff11.Output(out_cstr1_b);
            len_b += ff12.Output(out_cstr1_b);
            len_b += ff13.Output(out_cstr1_b);
            len_b += ff14.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff8.IsGood() == false);
                assert(ff8.IsBad() == true);
                assert(ff8.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff9.IsGood() == false);
                assert(ff9.IsBad() == true);
                assert(ff9.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff10.IsGood() == false);
                assert(ff10.IsBad() == true);
                assert(ff10.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff11.IsGood() == false);
                assert(ff11.IsBad() == true);
                assert(ff11.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff12.IsGood() == true);
                assert(ff12.IsBad() == false);
                assert(ff12.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff13.IsGood() == false);
                assert(ff13.IsBad() == true);
                assert(ff13.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff14.IsGood() == false);
                assert(ff14.IsBad() == true);
                assert(ff14.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }

        FloatingPoint<char> ff1_c{ff1};
        FloatingPoint<char> ff2_c{ff2};
        FloatingPoint<char> ff3_c{ff3};
        FloatingPoint<char> ff4_c{ff4};
        FloatingPoint<char> ff5_c{ff5};
        FloatingPoint<char> ff6_c{ff6};
        FloatingPoint<char> ff7_c{ff7};

        FloatingPoint<char> ff15{std::move(ff1_c)};
        FloatingPoint<char> ff16{std::move(ff2_c)};
        FloatingPoint<char> ff17{std::move(ff3_c)};
        FloatingPoint<char> ff18{std::move(ff4_c)};
        FloatingPoint<char> ff19{std::move(ff5_c)};
        FloatingPoint<char> ff20{std::move(ff6_c)};
        FloatingPoint<char> ff21{std::move(ff7_c)};

        
        {
            assert(ff15.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff15.GetValue()) ==
                l_double_val2);
            assert(ff15.GetWidth() == 0);
            assert(ff15.GetPrecision() == 0);
            assert(ff15.IsGood() == true);
            assert(ff15.IsBad() == false);
            assert(ff15.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff16.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff16.GetValue()) ==
                l_double_val2);
            assert(ff16.GetWidth() == wd1);
            assert(ff16.GetPrecision() == pres1);
            assert(ff16.IsGood() == true);
            assert(ff16.IsBad() == false);
            assert(ff16.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff17.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff17.GetValue()) ==
                l_double_val2);
            assert(ff17.GetWidth() == wd2);
            assert(ff17.GetPrecision() == pres1);
            assert(ff17.IsGood() == true);
            assert(ff17.IsBad() == false);
            assert(ff17.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff18.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff18.GetValue()) ==
                l_double_val2);
            assert(ff18.GetWidth() == wd1);
            assert(ff18.GetPrecision() == pres2);
            assert(ff18.IsGood() == true);
            assert(ff18.IsBad() == false);
            assert(ff18.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff19.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff19.GetValue()) ==
                float_val1);
            assert(ff19.GetWidth() == wd1);
            assert(ff19.GetPrecision() == pres1);
            assert(ff19.IsGood() == true);
            assert(ff19.IsBad() == false);
            assert(ff19.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff20.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff20.GetValue()) ==
                double_val1);
            assert(ff20.GetWidth() == wd2);
            assert(ff20.GetPrecision() == pres1);
            printf("%d\n", ff20.GetBadCode());
            assert(ff20.IsGood() == true);
            assert(ff20.IsBad() == false);
            assert(ff20.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff21.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff21.GetValue()) ==
                l_double_val1);
            assert(ff21.GetWidth() == wd1);
            assert(ff21.GetPrecision() == pres2);
            assert(ff21.IsGood() == true);
            assert(ff21.IsBad() == false);
            assert(ff21.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff15.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff16.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff17.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff18.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff19.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff20.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff21.GetValue()));
            auto len_b = ff15.Output(out_cstr1_b);
            len_b += ff16.Output(out_cstr1_b);
            len_b += ff17.Output(out_cstr1_b);
            len_b += ff18.Output(out_cstr1_b);
            len_b += ff19.Output(out_cstr1_b);
            len_b += ff20.Output(out_cstr1_b);
            len_b += ff21.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff15.IsGood() == true);
                assert(ff15.IsBad() == false);
                assert(ff15.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff16.IsGood() == true);
                assert(ff16.IsBad() == false);
                assert(ff16.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff17.IsGood() == true);
                assert(ff17.IsBad() == false);
                assert(ff17.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff18.IsGood() == true);
                assert(ff18.IsBad() == false);
                assert(ff18.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff19.IsGood() == true);
                assert(ff19.IsBad() == false);
                assert(ff19.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff20.IsGood() == true);
                assert(ff20.IsBad() == false);
                assert(ff20.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff21.IsGood() == true);
                assert(ff21.IsBad() == false);
                assert(ff21.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }

        {
            ff15.Unset();
            assert(ff15.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff15.GetValue()) == 
                0.0L);
            assert(ff15.GetWidth() == 0);
            assert(ff15.GetPrecision() == 0);
            assert(ff15.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff15.IsGood() == true);
            assert(ff15.IsBad() == false);
            assert(ff15.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff16.Unset();
            assert(ff16.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff16.GetValue()) ==
                0.0L);
            assert(ff16.GetWidth() == wd1);
            assert(ff16.GetPrecision() == pres1);
            assert(ff16.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff16.IsGood() == true);
            assert(ff16.IsBad() == false);
            assert(ff16.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff17.Unset();
            assert(ff17.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff17.GetValue()) ==
                0.0L);
            assert(ff17.GetWidth() == 0);
            assert(ff17.GetPrecision() == pres1);
            assert(ff17.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff17.IsGood() == true);
            assert(ff17.IsBad() == false);
            assert(ff17.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff18.Unset();
            assert(ff18.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff18.GetValue()) == 
                0.0L);
            assert(ff18.GetWidth() == wd1);
            assert(ff18.GetPrecision() == 0);
            assert(ff18.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff18.IsGood() == true);
            assert(ff18.IsBad() == false);
            assert(ff18.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff19.Unset();
            assert(ff19.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff19.GetValue()) ==
                float_val1);
            assert(ff19.GetWidth() == wd1);
            assert(ff19.GetPrecision() == pres1);
            assert(ff19.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff19.IsGood() == true);
            assert(ff19.IsBad() == false);
            assert(ff19.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff20.Unset();
            assert(ff20.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff20.GetValue()) ==
                double_val1);
            assert(ff20.GetWidth() == 0);
            assert(ff20.GetPrecision() == pres1);
            assert(ff20.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff20.IsGood() == true);
            assert(ff20.IsBad() == false);
            assert(ff20.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff21.Unset();
            assert(ff21.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff21.GetValue()) ==
                l_double_val1);
            assert(ff21.GetWidth() == wd1);
            assert(ff21.GetPrecision() == 0);
            assert(ff21.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff21.IsGood() == true);
            assert(ff21.IsBad() == false);
            assert(ff21.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff15.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff16.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff17.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff18.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff19.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff20.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff21.GetValue()));
            auto len_b = ff15.Output(out_cstr1_b);
            len_b += ff16.Output(out_cstr1_b);
            len_b += ff17.Output(out_cstr1_b);
            len_b += ff18.Output(out_cstr1_b);
            len_b += ff19.Output(out_cstr1_b);
            len_b += ff20.Output(out_cstr1_b);
            len_b += ff21.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff15.IsGood() == false);
                assert(ff15.IsBad() == true);
                assert(ff15.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff16.IsGood() == false);
                assert(ff16.IsBad() == true);
                assert(ff16.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff17.IsGood() == false);
                assert(ff17.IsBad() == true);
                assert(ff17.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff18.IsGood() == false);
                assert(ff18.IsBad() == true);
                assert(ff18.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff19.IsGood() == true);
                assert(ff19.IsBad() == false);
                assert(ff19.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff20.IsGood() == false);
                assert(ff20.IsBad() == true);
                assert(ff20.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff21.IsGood() == false);
                assert(ff21.IsBad() == true);
                assert(ff21.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            assert(ff1_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff1_c.GetValue()) == 
                0.0L);
            assert(ff1_c.GetWidth() == 0);
            assert(ff1_c.GetPrecision() == 0);
            assert(ff1_c.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff1_c.IsGood() == true);
            assert(ff1_c.IsBad() == false);
            assert(ff1_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff2_c.GetValue()) ==
                0.0L);
            assert(ff2_c.GetWidth() == wd1);
            assert(ff2_c.GetPrecision() == pres1);
            assert(ff2_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff2_c.IsGood() == true);
            assert(ff2_c.IsBad() == false);
            assert(ff2_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3_c.GetValue()) ==
                0.0L);
            assert(ff3_c.GetWidth() == 0);
            assert(ff3_c.GetPrecision() == pres1);
            assert(ff3_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff3_c.IsGood() == true);
            assert(ff3_c.IsBad() == false);
            assert(ff3_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff4_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff4_c.GetValue()) == 
                0.0L);
            assert(ff4_c.GetWidth() == wd1);
            assert(ff4_c.GetPrecision() == 0);
            assert(ff4_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff4_c.IsGood() == true);
            assert(ff4_c.IsBad() == false);
            assert(ff4_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff5_c.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff5_c.GetValue()) ==
                float_val1);
            assert(ff5_c.GetWidth() == wd1);
            assert(ff5_c.GetPrecision() == pres1);
            assert(ff5_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff5_c.IsGood() == true);
            assert(ff5_c.IsBad() == false);
            assert(ff5_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff6_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff6_c.GetValue()) ==
                double_val1);
            assert(ff6_c.GetWidth() == 0);
            assert(ff6_c.GetPrecision() == pres1);
            assert(ff6_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff6_c.IsGood() == true);
            assert(ff6_c.IsBad() == false);
            assert(ff6_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff7_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff7_c.GetValue()) ==
                l_double_val1);
            assert(ff7_c.GetWidth() == wd1);
            assert(ff7_c.GetPrecision() == 0);
            assert(ff7_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff7_c.IsGood() == true);
            assert(ff7_c.IsBad() == false);
            assert(ff7_c.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff1_c.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2_c.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff3_c.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff4_c.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff5_c.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff6_c.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff7_c.GetValue()));
            auto len_b = ff1_c.Output(out_cstr1_b);
            len_b += ff2_c.Output(out_cstr1_b);
            len_b += ff3_c.Output(out_cstr1_b);
            len_b += ff4_c.Output(out_cstr1_b);
            len_b += ff5_c.Output(out_cstr1_b);
            len_b += ff6_c.Output(out_cstr1_b);
            len_b += ff7_c.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1_c.IsGood() == false);
                assert(ff1_c.IsBad() == true);
                assert(ff1_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2_c.IsGood() == false);
                assert(ff2_c.IsBad() == true);
                assert(ff2_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3_c.IsGood() == false);
                assert(ff3_c.IsBad() == true);
                assert(ff3_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff4_c.IsGood() == false);
                assert(ff4_c.IsBad() == true);
                assert(ff4_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff5_c.IsGood() == true);
                assert(ff5_c.IsBad() == false);
                assert(ff5_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff6_c.IsGood() == false);
                assert(ff6_c.IsBad() == true);
                assert(ff6_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff7_c.IsGood() == false);
                assert(ff7_c.IsBad() == true);
                assert(ff7_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        FloatingPoint<char> ff22{};
        FloatingPoint<char> ff23{};
        FloatingPoint<char> ff24{};
        FloatingPoint<char> ff25{};
        FloatingPoint<char> ff26{};
        FloatingPoint<char> ff27{};
        FloatingPoint<char> ff28{};

        ff22 = ff1;
        ff23 = ff2;
        ff24 = ff3;
        ff25 = ff4;
        ff26 = ff5;
        ff27 = ff6;
        ff28 = ff7;
        {
            assert(ff22.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff22.GetValue()) ==
                l_double_val2);
            assert(ff22.GetWidth() == 0);
            assert(ff22.GetPrecision() == 0);
            assert(ff22.IsGood() == true);
            assert(ff22.IsBad() == false);
            assert(ff22.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff23.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff23.GetValue()) ==
                l_double_val2);
            assert(ff23.GetWidth() == wd1);
            assert(ff23.GetPrecision() == pres1);
            assert(ff23.IsGood() == true);
            assert(ff23.IsBad() == false);
            assert(ff23.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff24.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff24.GetValue()) ==
                l_double_val2);
            assert(ff24.GetWidth() == wd2);
            assert(ff24.GetPrecision() == pres1);
            assert(ff24.IsGood() == true);
            assert(ff24.IsBad() == false);
            assert(ff24.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff25.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff25.GetValue()) ==
                l_double_val2);
            assert(ff25.GetWidth() == wd1);
            assert(ff25.GetPrecision() == pres2);
            assert(ff25.IsGood() == true);
            assert(ff25.IsBad() == false);
            assert(ff25.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff26.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff26.GetValue()) ==
                float_val1);
            assert(ff26.GetWidth() == wd1);
            assert(ff26.GetPrecision() == pres1);
            assert(ff26.IsGood() == true);
            assert(ff26.IsBad() == false);
            assert(ff26.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff27.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff27.GetValue()) ==
                double_val1);
            assert(ff27.GetWidth() == wd2);
            assert(ff27.GetPrecision() == pres1);
            printf("%d\n", ff27.GetBadCode());
            assert(ff27.IsGood() == true);
            assert(ff27.IsBad() == false);
            assert(ff27.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff28.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff28.GetValue()) ==
                l_double_val1);
            assert(ff28.GetWidth() == wd1);
            assert(ff28.GetPrecision() == pres2);
            assert(ff28.IsGood() == true);
            assert(ff28.IsBad() == false);
            assert(ff28.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff22.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff23.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff24.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff25.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff26.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff27.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff28.GetValue()));
            auto len_b = ff22.Output(out_cstr1_b);
            len_b += ff23.Output(out_cstr1_b);
            len_b += ff24.Output(out_cstr1_b);
            len_b += ff25.Output(out_cstr1_b);
            len_b += ff26.Output(out_cstr1_b);
            len_b += ff27.Output(out_cstr1_b);
            len_b += ff28.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff22.IsGood() == true);
                assert(ff22.IsBad() == false);
                assert(ff22.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff23.IsGood() == true);
                assert(ff23.IsBad() == false);
                assert(ff23.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff24.IsGood() == true);
                assert(ff24.IsBad() == false);
                assert(ff24.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff25.IsGood() == true);
                assert(ff25.IsBad() == false);
                assert(ff25.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff26.IsGood() == true);
                assert(ff26.IsBad() == false);
                assert(ff26.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff27.IsGood() == true);
                assert(ff27.IsBad() == false);
                assert(ff27.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff28.IsGood() == true);
                assert(ff28.IsBad() == false);
                assert(ff28.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }

        {
            ff22.Unset();
            assert(ff22.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff22.GetValue()) == 
                0.0L);
            assert(ff22.GetWidth() == 0);
            assert(ff22.GetPrecision() == 0);
            assert(ff22.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff22.IsGood() == true);
            assert(ff22.IsBad() == false);
            assert(ff22.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff23.Unset();
            assert(ff23.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff23.GetValue()) ==
                0.0L);
            assert(ff23.GetWidth() == wd1);
            assert(ff23.GetPrecision() == pres1);
            assert(ff23.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff23.IsGood() == true);
            assert(ff23.IsBad() == false);
            assert(ff23.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff24.Unset();
            assert(ff24.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff24.GetValue()) ==
                0.0L);
            assert(ff24.GetWidth() == 0);
            assert(ff24.GetPrecision() == pres1);
            assert(ff24.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff24.IsGood() == true);
            assert(ff24.IsBad() == false);
            assert(ff24.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff25.Unset();
            assert(ff25.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff25.GetValue()) == 
                0.0L);
            assert(ff25.GetWidth() == wd1);
            assert(ff25.GetPrecision() == 0);
            assert(ff25.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff25.IsGood() == true);
            assert(ff25.IsBad() == false);
            assert(ff25.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff26.Unset();
            assert(ff26.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff26.GetValue()) ==
                float_val1);
            assert(ff26.GetWidth() == wd1);
            assert(ff26.GetPrecision() == pres1);
            assert(ff26.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff26.IsGood() == true);
            assert(ff26.IsBad() == false);
            assert(ff26.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff27.Unset();
            assert(ff27.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff27.GetValue()) ==
                double_val1);
            assert(ff27.GetWidth() == 0);
            assert(ff27.GetPrecision() == pres1);
            assert(ff27.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff27.IsGood() == true);
            assert(ff27.IsBad() == false);
            assert(ff27.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff28.Unset();
            assert(ff28.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff28.GetValue()) ==
                l_double_val1);
            assert(ff28.GetWidth() == wd1);
            assert(ff28.GetPrecision() == 0);
            assert(ff28.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff28.IsGood() == true);
            assert(ff28.IsBad() == false);
            assert(ff28.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff22.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff23.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff24.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff25.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff26.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff27.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff28.GetValue()));
            auto len_b = ff22.Output(out_cstr1_b);
            len_b += ff23.Output(out_cstr1_b);
            len_b += ff24.Output(out_cstr1_b);
            len_b += ff25.Output(out_cstr1_b);
            len_b += ff26.Output(out_cstr1_b);
            len_b += ff27.Output(out_cstr1_b);
            len_b += ff28.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff22.IsGood() == false);
                assert(ff22.IsBad() == true);
                assert(ff22.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff23.IsGood() == false);
                assert(ff23.IsBad() == true);
                assert(ff23.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff24.IsGood() == false);
                assert(ff24.IsBad() == true);
                assert(ff24.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff25.IsGood() == false);
                assert(ff25.IsBad() == true);
                assert(ff25.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff26.IsGood() == true);
                assert(ff26.IsBad() == false);
                assert(ff26.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff27.IsGood() == false);
                assert(ff27.IsBad() == true);
                assert(ff27.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff28.IsGood() == false);
                assert(ff28.IsBad() == true);
                assert(ff28.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }

        
        ff1_c = ff1;
        ff2_c = ff2;
        ff3_c = ff3;
        ff4_c = ff4;
        ff5_c = ff5;
        ff6_c = ff6;
        ff7_c = ff7;

        FloatingPoint<char> ff29{};
        FloatingPoint<char> ff30{};
        FloatingPoint<char> ff31{};
        FloatingPoint<char> ff32{};
        FloatingPoint<char> ff33{};
        FloatingPoint<char> ff34{};
        FloatingPoint<char> ff35{};

        ff29 = std::move(ff1_c);
        ff30 = std::move(ff2_c);
        ff31 = std::move(ff3_c);
        ff32 = std::move(ff4_c);
        ff33 = std::move(ff5_c);
        ff34 = std::move(ff6_c);
        ff35 = std::move(ff7_c);
        {
            assert(ff29.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff29.GetValue()) ==
                l_double_val2);
            assert(ff29.GetWidth() == 0);
            assert(ff29.GetPrecision() == 0);
            assert(ff29.IsGood() == true);
            assert(ff29.IsBad() == false);
            assert(ff29.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff30.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff30.GetValue()) ==
                l_double_val2);
            assert(ff30.GetWidth() == wd1);
            assert(ff30.GetPrecision() == pres1);
            assert(ff30.IsGood() == true);
            assert(ff30.IsBad() == false);
            assert(ff30.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff31.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff31.GetValue()) ==
                l_double_val2);
            assert(ff31.GetWidth() == wd2);
            assert(ff31.GetPrecision() == pres1);
            assert(ff31.IsGood() == true);
            assert(ff31.IsBad() == false);
            assert(ff31.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff32.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff32.GetValue()) ==
                l_double_val2);
            assert(ff32.GetWidth() == wd1);
            assert(ff32.GetPrecision() == pres2);
            assert(ff32.IsGood() == true);
            assert(ff32.IsBad() == false);
            assert(ff32.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff33.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff33.GetValue()) ==
                float_val1);
            assert(ff33.GetWidth() == wd1);
            assert(ff33.GetPrecision() == pres1);
            assert(ff33.IsGood() == true);
            assert(ff33.IsBad() == false);
            assert(ff33.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff34.IsSet() == true);
            assert(val::FloatingPoint::CastTo<double>(ff34.GetValue()) ==
                double_val1);
            assert(ff34.GetWidth() == wd2);
            assert(ff34.GetPrecision() == pres1);
            printf("%d\n", ff34.GetBadCode());
            assert(ff34.IsGood() == true);
            assert(ff34.IsBad() == false);
            assert(ff34.GetBadCode() == FloatingPoint<char>::StatusType::good);
            
            assert(ff35.IsSet() == true);
            assert(val::FloatingPoint::CastTo<long double>(ff35.GetValue()) ==
                l_double_val1);
            assert(ff35.GetWidth() == wd1);
            assert(ff35.GetPrecision() == pres2);
            assert(ff35.IsGood() == true);
            assert(ff35.IsBad() == false);
            assert(ff35.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }

        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff29.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff30.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff31.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff32.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff33.GetValue()),
                wd2, pres1, val::FloatingPoint::CastTo<long double>(ff34.GetValue()),
                wd1, pres2, val::FloatingPoint::CastTo<long double>(ff35.GetValue()));
            auto len_b = ff29.Output(out_cstr1_b);
            len_b += ff30.Output(out_cstr1_b);
            len_b += ff31.Output(out_cstr1_b);
            len_b += ff32.Output(out_cstr1_b);
            len_b += ff33.Output(out_cstr1_b);
            len_b += ff34.Output(out_cstr1_b);
            len_b += ff35.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff29.IsGood() == true);
                assert(ff29.IsBad() == false);
                assert(ff29.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff30.IsGood() == true);
                assert(ff30.IsBad() == false);
                assert(ff30.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff31.IsGood() == true);
                assert(ff31.IsBad() == false);
                assert(ff31.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff32.IsGood() == true);
                assert(ff32.IsBad() == false);
                assert(ff32.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff33.IsGood() == true);
                assert(ff33.IsBad() == false);
                assert(ff33.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);

                assert(ff34.IsGood() == true);
                assert(ff34.IsBad() == false);
                assert(ff34.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff35.IsGood() == true);
                assert(ff35.IsBad() == false);
                assert(ff35.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
            }
        }

        {
            ff29.Unset();
            assert(ff29.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff29.GetValue()) == 
                0.0L);
            assert(ff29.GetWidth() == 0);
            assert(ff29.GetPrecision() == 0);
            assert(ff29.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff29.IsGood() == true);
            assert(ff29.IsBad() == false);
            assert(ff29.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff30.Unset();
            assert(ff30.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff30.GetValue()) ==
                0.0L);
            assert(ff30.GetWidth() == wd1);
            assert(ff30.GetPrecision() == pres1);
            assert(ff30.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff30.IsGood() == true);
            assert(ff30.IsBad() == false);
            assert(ff30.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff31.Unset();
            assert(ff31.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff31.GetValue()) ==
                0.0L);
            assert(ff31.GetWidth() == 0);
            assert(ff31.GetPrecision() == pres1);
            assert(ff31.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff31.IsGood() == true);
            assert(ff31.IsBad() == false);
            assert(ff31.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff32.Unset();
            assert(ff32.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff32.GetValue()) == 
                0.0L);
            assert(ff32.GetWidth() == wd1);
            assert(ff32.GetPrecision() == 0);
            assert(ff32.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff32.IsGood() == true);
            assert(ff32.IsBad() == false);
            assert(ff32.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff33.Unset();
            assert(ff33.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff33.GetValue()) ==
                float_val1);
            assert(ff33.GetWidth() == wd1);
            assert(ff33.GetPrecision() == pres1);
            assert(ff33.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff33.IsGood() == true);
            assert(ff33.IsBad() == false);
            assert(ff33.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff34.Unset();
            assert(ff34.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff34.GetValue()) ==
                double_val1);
            assert(ff34.GetWidth() == 0);
            assert(ff34.GetPrecision() == pres1);
            assert(ff34.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff34.IsGood() == true);
            assert(ff34.IsBad() == false);
            assert(ff34.GetBadCode() == FloatingPoint<char>::StatusType::good);

            ff35.Unset();
            assert(ff35.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff35.GetValue()) ==
                l_double_val1);
            assert(ff35.GetWidth() == wd1);
            assert(ff35.GetPrecision() == 0);
            assert(ff35.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff35.IsGood() == true);
            assert(ff35.IsBad() == false);
            assert(ff35.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff29.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff30.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff31.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff32.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff33.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff34.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff35.GetValue()));
            auto len_b = ff29.Output(out_cstr1_b);
            len_b += ff30.Output(out_cstr1_b);
            len_b += ff31.Output(out_cstr1_b);
            len_b += ff32.Output(out_cstr1_b);
            len_b += ff33.Output(out_cstr1_b);
            len_b += ff34.Output(out_cstr1_b);
            len_b += ff35.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff29.IsGood() == false);
                assert(ff29.IsBad() == true);
                assert(ff29.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff30.IsGood() == false);
                assert(ff30.IsBad() == true);
                assert(ff30.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff31.IsGood() == false);
                assert(ff31.IsBad() == true);
                assert(ff31.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff32.IsGood() == false);
                assert(ff32.IsBad() == true);
                assert(ff32.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff33.IsGood() == true);
                assert(ff33.IsBad() == false);
                assert(ff33.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff34.IsGood() == false);
                assert(ff34.IsBad() == true);
                assert(ff34.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff35.IsGood() == false);
                assert(ff35.IsBad() == true);
                assert(ff35.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
        
        {
            assert(ff1_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff1_c.GetValue()) == 
                0.0L);
            assert(ff1_c.GetWidth() == 0);
            assert(ff1_c.GetPrecision() == 0);
            assert(ff1_c.GetFlag() == flag::FloatingPoint::p__uhe_long_double_format);
            assert(ff1_c.IsGood() == true);
            assert(ff1_c.IsBad() == false);
            assert(ff1_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff2_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff2_c.GetValue()) ==
                0.0L);
            assert(ff2_c.GetWidth() == wd1);
            assert(ff2_c.GetPrecision() == pres1);
            assert(ff2_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff2_c.IsGood() == true);
            assert(ff2_c.IsBad() == false);
            assert(ff2_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff3_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff3_c.GetValue()) ==
                0.0L);
            assert(ff3_c.GetWidth() == 0);
            assert(ff3_c.GetPrecision() == pres1);
            assert(ff3_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff3_c.IsGood() == true);
            assert(ff3_c.IsBad() == false);
            assert(ff3_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff4_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff4_c.GetValue()) == 
                0.0L);
            assert(ff4_c.GetWidth() == wd1);
            assert(ff4_c.GetPrecision() == 0);
            assert(ff4_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff4_c.IsGood() == true);
            assert(ff4_c.IsBad() == false);
            assert(ff4_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff5_c.IsSet() == true);
            assert(val::FloatingPoint::CastTo<float>(ff5_c.GetValue()) ==
                float_val1);
            assert(ff5_c.GetWidth() == wd1);
            assert(ff5_c.GetPrecision() == pres1);
            assert(ff5_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff5_c.IsGood() == true);
            assert(ff5_c.IsBad() == false);
            assert(ff5_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff6_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<double>(ff6_c.GetValue()) ==
                double_val1);
            assert(ff6_c.GetWidth() == 0);
            assert(ff6_c.GetPrecision() == pres1);
            assert(ff6_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff6_c.IsGood() == true);
            assert(ff6_c.IsBad() == false);
            assert(ff6_c.GetBadCode() == FloatingPoint<char>::StatusType::good);

            assert(ff7_c.IsSet() == false);
            assert(val::FloatingPoint::CastTo<long double>(ff7_c.GetValue()) ==
                l_double_val1);
            assert(ff7_c.GetWidth() == wd1);
            assert(ff7_c.GetPrecision() == 0);
            assert(ff7_c.GetFlag() == flag::FloatingPoint::p_wp_uhe_long_double_format);
            assert(ff7_c.IsGood() == true);
            assert(ff7_c.IsBad() == false);
            assert(ff7_c.GetBadCode() == FloatingPoint<char>::StatusType::good);
        }
        
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = 
                out_cstr1_a.Print("%#LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA%#*.*LA",
                val::FloatingPoint::CastTo<long double>(ff1_c.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff2_c.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff3_c.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff4_c.GetValue()),
                wd1, pres1, val::FloatingPoint::CastTo<long double>(ff5_c.GetValue()),
                0, pres1, val::FloatingPoint::CastTo<long double>(ff6_c.GetValue()),
                wd1, 0, val::FloatingPoint::CastTo<long double>(ff7_c.GetValue()));
            auto len_b = ff1_c.Output(out_cstr1_b);
            len_b += ff2_c.Output(out_cstr1_b);
            len_b += ff3_c.Output(out_cstr1_b);
            len_b += ff4_c.Output(out_cstr1_b);
            len_b += ff5_c.Output(out_cstr1_b);
            len_b += ff6_c.Output(out_cstr1_b);
            len_b += ff7_c.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);

            {
                assert(ff1_c.IsGood() == false);
                assert(ff1_c.IsBad() == true);
                assert(ff1_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff2_c.IsGood() == false);
                assert(ff2_c.IsBad() == true);
                assert(ff2_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
                    
                assert(ff3_c.IsGood() == false);
                assert(ff3_c.IsBad() == true);
                assert(ff3_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff4_c.IsGood() == false);
                assert(ff4_c.IsBad() == true);
                assert(ff4_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff5_c.IsGood() == true);
                assert(ff5_c.IsBad() == false);
                assert(ff5_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::good);
                    
                assert(ff6_c.IsGood() == false);
                assert(ff6_c.IsBad() == true);
                assert(ff6_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);

                assert(ff7_c.IsGood() == false);
                assert(ff7_c.IsBad() == true);
                assert(ff7_c.GetBadCode() == 
                    FloatingPoint<char>::StatusType::value_not_set);
            }
        }
    }
    return 1;
}