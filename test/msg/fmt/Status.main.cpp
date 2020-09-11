#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/fmt/Status.h"

#include <cassert>
#include <cstdint>
#include <utility>

int main()
{
    using namespace test::msg::fmt;
    {
        typedef Status<std::uint8_t> StatusType;
        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.GetBadCode() == StatusType::good);

        StatusType s2;

        assert(s2.Bad(StatusType::bad) == true);
        assert(s2.IsGood() == false);
        assert(s2.IsBad() == true);
        assert(s2.GetBadCode() == StatusType::bad);
        assert(s2.Bad(StatusType::bad) == false);
        assert(s2.GetBadCode() == StatusType::bad);

        StatusType s3{s2};
        
        assert(s3.IsGood() == false);
        assert(s3.IsBad() == true);
        assert(s3.GetBadCode() == StatusType::bad);

        StatusType s4{std::move(s2)};
        
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.GetBadCode() == StatusType::bad);
        
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.GetBadCode() == StatusType::good);

        StatusType s5;
        s5 = s3;

        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.GetBadCode() == StatusType::bad);
        
        StatusType s6;
        s6 = std::move(s3);
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.GetBadCode() == StatusType::bad);
        
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.GetBadCode() == StatusType::good);

        s6.Reset();
        
        assert(s6.IsGood() == true);
        assert(s6.IsBad() == false);
        assert(s6.GetBadCode() == StatusType::good);

        StatusType s7;

        s7.Bad(StatusType::value_not_set);
        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.GetBadCode() == StatusType::value_not_set);

        s7.Reset(StatusType::value_not_set);
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.GetBadCode() == StatusType::good);

        s7.Bad(StatusType::load_failed);
        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.GetBadCode() == StatusType::load_failed);
        
        s7.Reset(StatusType::load_failed);
        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.GetBadCode() == StatusType::load_failed);

        StatusType s8{s7};

        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.GetBadCode() == StatusType::load_failed);

        StatusType s9{std::move(s8)};

        assert(s9.IsGood() == false);
        assert(s9.IsBad() == true);
        assert(s9.GetBadCode() == StatusType::load_failed);

        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.GetBadCode() == StatusType::good);

        StatusType s10;
        s10 = s9;

        assert(s10.IsGood() == false);
        assert(s10.IsBad() == true);
        assert(s10.GetBadCode() == StatusType::load_failed);

        StatusType s11;
        s11 = std::move(s10);

        assert(s11.IsGood() == false);
        assert(s11.IsBad() == true);
        assert(s11.GetBadCode() == StatusType::load_failed);

        assert(s10.IsGood() == true);
        assert(s10.IsBad() == false);
        assert(s10.GetBadCode() == StatusType::good);

    }
    
    return TEST::GetInstance().Status().Get();
}
