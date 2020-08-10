#include "test/msg/fmt/val/flag/Nothing.h"

#include <cassert>
#include <utility>

int main()
{
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt::var;
    {
        constexpr Nothing nt1{};

        assert(nt1.GetValue() == Nothing::define_int);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_int);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_int);
        assert(nt2.GetValue() == Nothing::define_int);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_int);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_int);
        assert(nt4.GetValue() == Nothing::define_int);
    }
    {
        constexpr Nothing nt1{arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_int | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<char>{}};

        assert(nt1.GetValue() == Nothing::define_char);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_char);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_char);
        assert(nt2.GetValue() == Nothing::define_char);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_char);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_char);
        assert(nt4.GetValue() == Nothing::define_char);
    }
    {
        constexpr Nothing nt1{arg::Define<char>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<char>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_char | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<char>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<signed char>{}};

        assert(nt1.GetValue() == Nothing::define_char);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_char);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_char);
        assert(nt2.GetValue() == Nothing::define_char);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_char);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_char);
        assert(nt4.GetValue() == Nothing::define_char);
    }
    {
        constexpr Nothing nt1{arg::Define<signed char>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<signed char>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_char | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<signed char>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<unsigned char>{}};

        assert(nt1.GetValue() == Nothing::define_char);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_char);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_char);
        assert(nt2.GetValue() == Nothing::define_char);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_char);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_char);
        assert(nt4.GetValue() == Nothing::define_char);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned char>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned char>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_char | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<unsigned char>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_char | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<short>{}};

        assert(nt1.GetValue() == Nothing::define_short);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_short);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_short);
        assert(nt2.GetValue() == Nothing::define_short);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_short);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_short);
        assert(nt4.GetValue() == Nothing::define_short);
    }
    {
        constexpr Nothing nt1{arg::Define<short>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_short | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_short | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_short | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<short>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_short | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_short | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_short | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_short | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_short | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_short | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<short>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<unsigned short>{}};

        assert(nt1.GetValue() == Nothing::define_short);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_short);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_short);
        assert(nt2.GetValue() == Nothing::define_short);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_short);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_short);
        assert(nt4.GetValue() == Nothing::define_short);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned short>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_short | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_short | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_short | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned short>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_short | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_short | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_short | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_short | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_short | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_short | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<unsigned short>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_short | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<int>{}};

        assert(nt1.GetValue() == Nothing::define_int);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_int);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_int);
        assert(nt2.GetValue() == Nothing::define_int);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_int);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_int);
        assert(nt4.GetValue() == Nothing::define_int);
    }
    {
        constexpr Nothing nt1{arg::Define<int>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<int>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_int | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<int>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<unsigned int>{}};

        assert(nt1.GetValue() == Nothing::define_int);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_int);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_int);
        assert(nt2.GetValue() == Nothing::define_int);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_int);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_int);
        assert(nt4.GetValue() == Nothing::define_int);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned int>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned int>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_int | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<unsigned int>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_int | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<long>{}};

        assert(nt1.GetValue() == Nothing::define_long);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_long);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_long);
        assert(nt2.GetValue() == Nothing::define_long);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_long);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_long);
        assert(nt4.GetValue() == Nothing::define_long);
    }
    {
        constexpr Nothing nt1{arg::Define<long>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_long | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<long>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_long | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<long>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<unsigned long>{}};

        assert(nt1.GetValue() == Nothing::define_long);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_long);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_long);
        assert(nt2.GetValue() == Nothing::define_long);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_long);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_long);
        assert(nt4.GetValue() == Nothing::define_long);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_long | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_long | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<unsigned long>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long | Nothing::width |   
            Nothing::precision));
    }
    
    ///
    {
        constexpr Nothing nt1{arg::Define<long long>{}};

        assert(nt1.GetValue() == Nothing::define_long_long);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_long_long);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_long_long);
        assert(nt2.GetValue() == Nothing::define_long_long);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_long_long);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_long_long);
        assert(nt4.GetValue() == Nothing::define_long_long);
    }
    {
        constexpr Nothing nt1{arg::Define<long long>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_long | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_long_long | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_long | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<long long>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<long long>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<unsigned long long>{}};

        assert(nt1.GetValue() == Nothing::define_long_long);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_long_long);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_long_long);
        assert(nt2.GetValue() == Nothing::define_long_long);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_long_long);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_long_long);
        assert(nt4.GetValue() == Nothing::define_long_long);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long long>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_long | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_long_long | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_long | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long long>{}, 
            arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long_long | 
            Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<unsigned long long>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_long_long |  Nothing::width | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long_long | Nothing::width |
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<float>{}};

        assert(nt1.GetValue() == Nothing::define_double);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_double);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_double);
        assert(nt2.GetValue() == Nothing::define_double);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_double);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_double);
        assert(nt4.GetValue() == Nothing::define_double);
    }
    {
        constexpr Nothing nt1{arg::Define<float>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_double | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_double | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_double | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<float>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_double | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_double | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_double | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_double | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_double | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_double | Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<float>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width |   
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<double>{}};

        assert(nt1.GetValue() == Nothing::define_double);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_double);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_double);
        assert(nt2.GetValue() == Nothing::define_double);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_double);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_double);
        assert(nt4.GetValue() == Nothing::define_double);
    }
    {
        constexpr Nothing nt1{arg::Define<double>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_double | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_double | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_double | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<double>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_double | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_double | 
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_double | 
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_double | 
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_double | 
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_double | 
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_double | 
            Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<double>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_double | Nothing::width |
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<long double>{}};

        assert(nt1.GetValue() == Nothing::define_long_double);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_long_double);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_long_double);
        assert(nt2.GetValue() == Nothing::define_long_double);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_long_double);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_long_double);
        assert(nt4.GetValue() == Nothing::define_long_double);
    }
    {
        constexpr Nothing nt1{arg::Define<long double>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_long_double | 
            Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_double | 
            Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_double | 
            Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_long_double | 
            Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_double | 
            Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_double | 
            Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_long_double | 
            Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<long double>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long_double | 
            Nothing::precision));
    }
    
    {
        constexpr Nothing nt1{arg::Define<long double>{}, arg::Width{},
            arg::Precision{}};

        assert(nt1.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_long_double | 
            Nothing::width | Nothing::precision));
    }
    
    ///
    {
        constexpr Nothing nt1{arg::Define<const char *>{}};

        assert(nt1.GetValue() == Nothing::define_pointer);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_pointer);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_pointer);
        assert(nt2.GetValue() == Nothing::define_pointer);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_pointer);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_pointer);
        assert(nt4.GetValue() == Nothing::define_pointer);
    }
    {
        constexpr Nothing nt1{arg::Define<const char *>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_pointer | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_pointer | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_pointer | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_pointer | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_pointer | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_pointer | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_pointer | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<const char *>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
    }
    ///
    {
        constexpr Nothing nt1{arg::Define<const void *>{}};

        assert(nt1.GetValue() == Nothing::define_pointer);

        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_pointer);

        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == Nothing::define_pointer);
        assert(nt2.GetValue() == Nothing::define_pointer);

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == Nothing::define_pointer);
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == Nothing::define_pointer);
        assert(nt4.GetValue() == Nothing::define_pointer);
    }
    {
        constexpr Nothing nt1{arg::Define<const void *>{}, arg::Width{}};

        assert(nt1.GetValue() == (Nothing::define_pointer | Nothing::width));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_pointer | Nothing::width));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_pointer | Nothing::width));
        assert(nt2.GetValue() == (Nothing::define_pointer | Nothing::width));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_pointer | Nothing::width));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_pointer | Nothing::width));
        assert(nt4.GetValue() == (Nothing::define_pointer | Nothing::width));
    }
    {
        constexpr Nothing nt1{arg::Define<const void *>{}, arg::Precision{}};

        assert(Nothing::precision == Nothing::length);
        assert(nt1.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        
        constexpr Nothing nt2{nt1};

        assert(nt1.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        
        constexpr Nothing nt3{std::move(nt2)};

        assert(nt3.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        assert(nt2.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));

        Nothing nt4{};
        nt4 = nt3;

        assert(nt4.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        
        Nothing nt5{};
        nt5 = std::move(nt4);

        assert(nt5.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
        assert(nt4.GetValue() == (Nothing::define_pointer | 
            Nothing::precision));
    }
    return 1;
}