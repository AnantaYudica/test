#include "test/math/Logarithm.h"

#include <cmath>
#include <cfloat>
#include <cassert>

int main()
{
    {
        constexpr float f1 = 1.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));

    }
    {
        constexpr float f1 = 2.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));
    }
    {
        constexpr float f1 = 3.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 4.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 5.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 7.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 8.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 9.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 10.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 11.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 12.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 13.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 14.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 15.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 16.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 17.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 18.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 19.0f;
        constexpr float l1 = test::math::Logarithm<float, 2>(f1);
        float l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }

    {
        constexpr float f1 = 1.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));

    }
    {
        constexpr float f1 = 2.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);
        
        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));
    }
    {
        constexpr float f1 = 3.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 4.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 5.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 7.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 8.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 9.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 10.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 11.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 12.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 13.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 14.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 15.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 16.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 17.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 18.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 19.0f;
        constexpr float l1 = test::math::Logarithm<float, 8>(f1);
        float l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    
    {
        constexpr float f1 = 1.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));

    }
    {
        constexpr float f1 = 2.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);
        
        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));
    }
    {
        constexpr float f1 = 3.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 4.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 5.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 7.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 8.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 9.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 10.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 11.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 12.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 13.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 14.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 15.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 16.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 17.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 18.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 19.0f;
        constexpr float l1 = test::math::Logarithm<float, 10>(f1);
        float l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    
    {
        constexpr float f1 = 1.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));

    }
    {
        constexpr float f1 = 2.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);
        
        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));
    }
    {
        constexpr float f1 = 3.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 4.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 5.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 7.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 8.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 9.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 10.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 11.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 12.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 13.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 14.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 15.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 16.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 17.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 18.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 19.0f;
        constexpr float l1 = test::math::Logarithm<float, 16>(f1);
        float l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    
    {
        constexpr float f1 = 1.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));

    }
    {
        constexpr float f1 = 2.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);
        
        assert(std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)) ||
            std::floor(std::pow(l1, FLT_DIG)) ==
            std::floor(std::pow(l2, FLT_DIG)));
    }
    {
        constexpr float f1 = 3.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 4.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 5.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 7.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 8.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 9.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 10.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 11.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 12.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 13.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 14.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 15.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 16.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 17.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 18.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 19.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 23.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 29.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 31.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 37.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 41.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 43.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 47.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 53.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    {
        constexpr float f1 = 59.0f;
        constexpr float l1 = test::math::Logarithm<float, 54>(f1);
        float l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)) ||
            std::floor(std::pow(l1, FLT_DIG - 1)) ==
            std::floor(std::pow(l2, FLT_DIG - 1)));
    }
    //double
    {
        constexpr double f1 = 1.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));

    }
    {
        constexpr double f1 = 2.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));
    }
    {
        constexpr double f1 = 3.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 4.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 5.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 7.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 8.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 9.0;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 10.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 11.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 12.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 13.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 14.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 15.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 16.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 17.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 18.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 19.0f;
        constexpr double l1 = test::math::Logarithm<double, 2>(f1);
        double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }

    {
        constexpr double f1 = 1.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));

    }
    {
        constexpr double f1 = 2.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);
        
        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));
    }
    {
        constexpr double f1 = 3.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 4.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 5.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 7.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 8.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 9.0;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 10.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 11.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 12.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 13.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 14.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 15.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 16.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 17.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 18.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 19.0f;
        constexpr double l1 = test::math::Logarithm<double, 8>(f1);
        double l2 = std::log(f1) / std::log(8);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    
    {
        constexpr double f1 = 1.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));

    }
    {
        constexpr double f1 = 2.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);
        
        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));
    }
    {
        constexpr double f1 = 3.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 4.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 5.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 7.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 8.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 9.0;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 10.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 11.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 12.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 13.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 14.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 15.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 16.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 17.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 18.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 19.0f;
        constexpr double l1 = test::math::Logarithm<double, 10>(f1);
        double l2 = std::log(f1) / std::log(10);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    
    {
        constexpr double f1 = 1.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));

    }
    {
        constexpr double f1 = 2.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);
        
        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));
    }
    {
        constexpr double f1 = 3.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 4.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 5.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 7.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 8.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 9.0;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 10.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 11.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 12.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 13.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 14.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 15.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 16.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 17.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 18.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 19.0f;
        constexpr double l1 = test::math::Logarithm<double, 16>(f1);
        double l2 = std::log(f1) / std::log(16);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    
    {
        constexpr double f1 = 1.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));

    }
    {
        constexpr double f1 = 2.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);
        
        assert(std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)) ||
            std::floor(std::pow(l1, DBL_DIG)) ==
            std::floor(std::pow(l2, DBL_DIG)));
    }
    {
        constexpr double f1 = 3.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 4.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 5.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 7.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 8.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 9.0;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 10.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 11.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 12.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 13.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 14.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 15.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 16.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 17.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 18.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 19.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 23.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 29.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 31.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 37.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 41.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 43.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 47.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 53.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    {
        constexpr double f1 = 59.0f;
        constexpr double l1 = test::math::Logarithm<double, 54>(f1);
        double l2 = std::log(f1) / std::log(54);

        assert(std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)) ||
            std::floor(std::pow(l1, DBL_DIG - 1)) ==
            std::floor(std::pow(l2, DBL_DIG - 1)));
    }
    //long double
    
    {
        constexpr long double f1 = 1.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));

    }
    {
        constexpr long double f1 = 2.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 3.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 4.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 5.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 7.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);
        
        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 8.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 9.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 10.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 11.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 12.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 13.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 14.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 15.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 16.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 17.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 18.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 19.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 2>(f1);
        long double l2 = std::log2(f1);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }

    {
        constexpr long double f1 = 1.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));

    }
    {
        constexpr long double f1 = 2.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);
        
        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 3.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 4.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 5.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 7.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 8.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 9.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 10.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 11.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 12.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 13.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 14.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 15.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 16.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 17.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 18.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 19.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 8>(f1);
        long double l2 = std::log(f1) / std::log(8.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    
    {
        constexpr long double f1 = 1.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));

    }
    {
        constexpr long double f1 = 2.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);
        
        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 3.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 4.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 5.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 7.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 8.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 9.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 10.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);
        
        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 11.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 12.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 13.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 14.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 15.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 16.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 17.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 18.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 19.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 10>(f1);
        long double l2 = std::log(f1) / std::log(10.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    
    {
        constexpr long double f1 = 1.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));

    }
    {
        constexpr long double f1 = 2.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);
        
        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 3.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 4.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 5.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 7.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 8.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 9.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 10.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 11.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 12.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 13.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 14.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 15.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 16.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 17.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 18.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 19.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 16>(f1);
        long double l2 = std::log(f1) / std::log(16.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    
    {
        constexpr long double f1 = 1.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));

    }
    {
        constexpr long double f1 = 2.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);
        
        assert(std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)) ||
            std::floor(std::pow(l1, LDBL_DIG)) ==
            std::floor(std::pow(l2, LDBL_DIG)));
    }
    {
        constexpr long double f1 = 3.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 4.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 5.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 7.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 8.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 9.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 10.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 11.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 12.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 13.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 14.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 15.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 16.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 17.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 18.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 19.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 23.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 29.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 31.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 37.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 41.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 43.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 47.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 53.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    {
        constexpr long double f1 = 59.0L;
        constexpr long double l1 = test::math::Logarithm<long double, 54>(f1);
        long double l2 = std::log(f1) / std::log(54.0L);

        assert(std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)) ||
            std::floor(std::pow(l1, LDBL_DIG - 1)) ==
            std::floor(std::pow(l2, LDBL_DIG - 1)));
    }
    return 0;
}
