#include "test/math/Exponential.h"

#include <cmath>
#include <cassert>
#include <cfloat>

int main()
{
    {
        constexpr float x1 = 0.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        
        assert(e1 == 1.0f);
    }
    {
        constexpr float x1 = 1.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 2.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 3.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 2)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 2)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 2)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 2)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG + 1)) == 
            std::floor(e4 * std::pow(10, FLT_DIG + 1)) ||
            std::round(e3 * std::pow(10, FLT_DIG + 1)) == 
            std::round(e4 * std::pow(10, FLT_DIG + 1)));
    }
    
    {
        constexpr float x1 = 5.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 3)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 3)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 3)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 3)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG + 2)) == 
            std::floor(e4 * std::pow(10, FLT_DIG + 2)) || 
            std::round(e3 * std::pow(10, FLT_DIG + 2)) == 
            std::round(e4 * std::pow(10, FLT_DIG + 2)));
    }
    
    {
        constexpr float x1 = 7.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 4)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 4)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 4)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 4)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG + 3)) == 
            std::floor(e4 * std::pow(10, FLT_DIG + 3)) ||
            std::round(e3 * std::pow(10, FLT_DIG + 3)) == 
            std::round(e4 * std::pow(10, FLT_DIG + 3)));
    }
    
    {
        constexpr float x1 = 11.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 5)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 5)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 5)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 5)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG + 4)) == 
            std::floor(e4 * std::pow(10, FLT_DIG + 4)) ||
            std::round(e3 * std::pow(10, FLT_DIG + 4)) == 
            std::round(e4 * std::pow(10, FLT_DIG + 4)));
    }
    
    {
        constexpr float x1 = 13.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 6)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 6)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 6)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 6)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG + 5)) == 
            std::floor(e4 * std::pow(10, FLT_DIG + 5)) ||
            std::round(e3 * std::pow(10, FLT_DIG + 5)) == 
            std::round(e4 * std::pow(10, FLT_DIG + 5)));
    }
    
    {
        constexpr float x1 = 17.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 8)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 8)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 8)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 8)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG + 7)) == 
            std::floor(e4 * std::pow(10, FLT_DIG + 7)) ||
            std::round(e3 * std::pow(10, FLT_DIG + 7)) == 
            std::round(e4 * std::pow(10, FLT_DIG + 7)));
    }

    {
        constexpr float x1 = 1/2.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 1/3.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 1/5.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 1/7.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 1/11.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 1/13.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    
    {
        constexpr float x1 = 1/17.0f;
        constexpr float e1 = test::math::Exponential<float>(x1);
        const float e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::floor(e2 * std::pow(10, FLT_DIG - 1)) ||
            std::round(e1 * std::pow(10, FLT_DIG - 1)) == 
            std::round(e2 * std::pow(10, FLT_DIG - 1)));

        constexpr float x2 = -x1;
        constexpr float e3 = test::math::Exponential<float>(x2);
        const float e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, FLT_DIG)) == 
            std::floor(e4 * std::pow(10, FLT_DIG)) ||
            std::round(e3 * std::pow(10, FLT_DIG)) == 
            std::round(e4 * std::pow(10, FLT_DIG)));
    }
    //double
    
    {
        constexpr double x1 = 0.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        
        assert(e1 == 1.0);
    }
    {
        constexpr double x1 = 1.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 2.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 3.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 2)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 2)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 2)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 2)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG + 1)) == 
            std::floor(e4 * std::pow(10, DBL_DIG + 1)) ||
            std::round(e3 * std::pow(10, DBL_DIG + 1)) == 
            std::round(e4 * std::pow(10, DBL_DIG + 1)));
    }
    
    {
        constexpr double x1 = 5.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 3)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 3)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 3)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 3)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG + 2)) == 
            std::floor(e4 * std::pow(10, DBL_DIG + 2)) || 
            std::round(e3 * std::pow(10, DBL_DIG + 2)) == 
            std::round(e4 * std::pow(10, DBL_DIG + 2)));
    }
    
    {
        constexpr double x1 = 7.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 4)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 4)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 4)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 4)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG + 3)) == 
            std::floor(e4 * std::pow(10, DBL_DIG + 3)) ||
            std::round(e3 * std::pow(10, DBL_DIG + 3)) == 
            std::round(e4 * std::pow(10, DBL_DIG + 3)));
    }
    
    {
        constexpr double x1 = 11.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 5)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 5)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 5)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 5)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG + 4)) == 
            std::floor(e4 * std::pow(10, DBL_DIG + 4)) ||
            std::round(e3 * std::pow(10, DBL_DIG + 4)) == 
            std::round(e4 * std::pow(10, DBL_DIG + 4)));
    }
    
    {
        constexpr double x1 = 13.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 6)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 6)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 6)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 6)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG + 5)) == 
            std::floor(e4 * std::pow(10, DBL_DIG + 5)) ||
            std::round(e3 * std::pow(10, DBL_DIG + 5)) == 
            std::round(e4 * std::pow(10, DBL_DIG + 5)));
    }
    
    {
        constexpr double x1 = 17.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 8)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 8)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 8)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 8)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG + 7)) == 
            std::floor(e4 * std::pow(10, DBL_DIG + 7)) ||
            std::round(e3 * std::pow(10, DBL_DIG + 7)) == 
            std::round(e4 * std::pow(10, DBL_DIG + 7)));
    }

    {
        constexpr double x1 = 1/2.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 1/3.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 1/5.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 1/7.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 1/11.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 1/13.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    
    {
        constexpr double x1 = 1/17.0;
        constexpr double e1 = test::math::Exponential<double>(x1);
        const double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, DBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, DBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, DBL_DIG - 1)));

        constexpr double x2 = -x1;
        constexpr double e3 = test::math::Exponential<double>(x2);
        const double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, DBL_DIG)) == 
            std::floor(e4 * std::pow(10, DBL_DIG)) ||
            std::round(e3 * std::pow(10, DBL_DIG)) == 
            std::round(e4 * std::pow(10, DBL_DIG)));
    }
    //long double
    
    {
        constexpr long double x1 = 0.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        
        assert(e1 == 1.0L);
    }
    {
        constexpr long double x1 = 1.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 2.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 3.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 2)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 2)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 2)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 2)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG + 1)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG + 1)) ||
            std::round(e3 * std::pow(10, LDBL_DIG + 1)) == 
            std::round(e4 * std::pow(10, LDBL_DIG + 1)));
    }
    
    {
        constexpr long double x1 = 5.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 3)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 3)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 3)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 3)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG + 2)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG + 2)) || 
            std::round(e3 * std::pow(10, LDBL_DIG + 2)) == 
            std::round(e4 * std::pow(10, LDBL_DIG + 2)));
    }
    
    {
        constexpr long double x1 = 7.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 4)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 4)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 4)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 4)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG + 3)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG + 3)) ||
            std::round(e3 * std::pow(10, LDBL_DIG + 3)) == 
            std::round(e4 * std::pow(10, LDBL_DIG + 3)));
    }
    
    {
        constexpr long double x1 = 11.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 5)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 5)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 5)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 5)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG + 4)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG + 4)) ||
            std::round(e3 * std::pow(10, LDBL_DIG + 4)) == 
            std::round(e4 * std::pow(10, LDBL_DIG + 4)));
    }
    
    {
        constexpr long double x1 = 13.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 6)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 6)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 6)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 6)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG + 5)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG + 5)) ||
            std::round(e3 * std::pow(10, LDBL_DIG + 5)) == 
            std::round(e4 * std::pow(10, LDBL_DIG + 5)));
    }
    
    {
        constexpr long double x1 = 17.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 8)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 8)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 8)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 8)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG + 7)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG + 7)) ||
            std::round(e3 * std::pow(10, LDBL_DIG + 7)) == 
            std::round(e4 * std::pow(10, LDBL_DIG + 7)));
    }

    {
        constexpr long double x1 = 1/2.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 1/3.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 1/5.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 1/7.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 1/11.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 1/13.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    
    {
        constexpr long double x1 = 1/17.0L;
        constexpr long double e1 = test::math::Exponential<long double>(x1);
        const long double e2 = std::exp(x1);

        assert(std::floor(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::floor(e2 * std::pow(10, LDBL_DIG - 1)) ||
            std::round(e1 * std::pow(10, LDBL_DIG - 1)) == 
            std::round(e2 * std::pow(10, LDBL_DIG - 1)));

        constexpr long double x2 = -x1;
        constexpr long double e3 = test::math::Exponential<long double>(x2);
        const long double e4 = std::exp(x2);
        
        assert(std::floor(e3 * std::pow(10, LDBL_DIG)) == 
            std::floor(e4 * std::pow(10, LDBL_DIG)) ||
            std::round(e3 * std::pow(10, LDBL_DIG)) == 
            std::round(e4 * std::pow(10, LDBL_DIG)));
    }
    return 0;
}
