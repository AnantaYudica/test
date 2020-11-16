#include "test/math/NaturalLogarithm.h"

#include <cfloat>
#include <cmath>
#include <cassert>

int main()
{
    {
        constexpr float f1 = 1.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);

        const float l2 = std::log(f1);

        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = 2.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = 3.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 5.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 7.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 11.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 13.0f;
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 17.0f;
        float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)2);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)3);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)5);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)7);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)11);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG + 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG + 1)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)13);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG + 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG + 1)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)17);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG + 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG + 1)));
    }
    {
        constexpr float f1 = 1.0f + (1 / (float)19);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG + 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG + 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG + 1)));
    }
    
    {
        constexpr float f1 = (1 / (float)2);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG)) == 
            std::floor(l2 * std::pow(10, FLT_DIG)) ||
            std::round(l1 * std::pow(10, FLT_DIG)) == 
            std::round(l2 * std::pow(10, FLT_DIG)));
    }
    {
        constexpr float f1 = (1 / (float)3);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = (1 / (float)5);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = (1 / (float)7);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = (1 / (float)11);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = (1 / (float)13);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = (1 / (float)17);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = (1 / (float)19);
        constexpr float l1 = test::math::NaturalLogarithm<float>(f1);
        const float l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(l2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(l1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(l2 * std::pow(10, FLT_DIG - 1)));
    }
    //double
    
    {
        constexpr double f1 = 1.0;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);

        const double l2 = std::log(f1);

        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = 2.0;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = 3.0;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 5.0;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 7.0;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 11.0f;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 13.0f;
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 17.0f;
        double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)2);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)3);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)5);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)7);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)11);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG + 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG + 1)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)13);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG + 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG + 1)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)17);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG + 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG + 1)));
    }
    {
        constexpr double f1 = 1.0 + (1 / (double)19);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG + 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG + 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG + 1)));
    }
    
    {
        constexpr double f1 = (1 / (double)2);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG)) == 
            std::floor(l2 * std::pow(10, DBL_DIG)) ||
            std::round(l1 * std::pow(10, DBL_DIG)) == 
            std::round(l2 * std::pow(10, DBL_DIG)));
    }
    {
        constexpr double f1 = (1 / (double)3);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = (1 / (double)5);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = (1 / (double)7);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = (1 / (double)11);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = (1 / (double)13);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = (1 / (double)17);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = (1 / (double)19);
        constexpr double l1 = test::math::NaturalLogarithm<double>(f1);
        const double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, DBL_DIG - 1)));
    }
    //long double
    
    {
        constexpr long double f1 = 1.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);

        const long double l2 = std::log(f1);

        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 2.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 3.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 5.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 7.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 11.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 13.0L;
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 17.0L;
        long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)2);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)3);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)5);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)7);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)11);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);

        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)13);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)17);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 1.0L + (1 / (long double)19);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double f1 = (1 / (long double)2);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG)) ||
            std::round(l1 * std::pow(10, LDBL_DIG)) == 
            std::round(l2 * std::pow(10, LDBL_DIG)));
    }
    {
        constexpr long double f1 = (1 / (long double)3);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = (1 / (long double)5);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = (1 / (long double)7);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = (1 / (long double)11);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = (1 / (long double)13);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = (1 / (long double)17);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = (1 / (long double)19);
        constexpr long double l1 = test::math::NaturalLogarithm<long double>(f1);
        const long double l2 = std::log(f1);
        
        assert(std::floor(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(l2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(l1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(l2 * std::pow(10, LDBL_DIG - 1)));
    }
    return 0;
}
