#include "test/msg/fmt/val/flag/Nothing.h"

#include <cassert>
#include <utility>

int main()
{
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt::var;
    {
        constexpr Nothing nt1{};

        assert(nt1.GetValue() == Nothing::good);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::good);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::good);
        assert(nt2.GetValue() == Nothing::good);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::good);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::good);
        assert(nt4.GetValue() == Nothing::good);
    }
    {
        constexpr Nothing nt1{arg::Width{}};

        assert(nt1.GetValue() == Nothing::width);
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == Nothing::width);
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::width);
        assert(nt2.GetValue() == Nothing::width);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::width);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::width);
        assert(nt4.GetValue() == Nothing::width);
    }
    {
        constexpr Nothing nt1{arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == Nothing::precision);
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == Nothing::precision);
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::precision);
        assert(nt2.GetValue() == Nothing::precision);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::precision);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::precision);
        assert(nt4.GetValue() == Nothing::precision);
    }
    
    {
        constexpr Nothing nt1{arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::width |   
            Nothing::precision));
    }
    return 1;
}