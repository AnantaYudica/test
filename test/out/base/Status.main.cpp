#include "test/out/base/Status.h"

#include <cstdint>
#include <cassert>
#include <utility>
#include <atomic>

int main()
{
    using namespace test::out::base;
    {
        typedef Status<std::uint8_t> StatusType;
        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.GetBadCode() == StatusType::good);

        StatusType s2;
        assert(s2.Bad(StatusType::queue_overflow) == true);
        assert(s2.IsGood() == false);
        assert(s2.IsBad() == true);
        assert(s2.GetBadCode() == StatusType::queue_overflow);
        assert(s2.Bad(StatusType::task_request_failed) == false);
        assert(s2.GetBadCode() == StatusType::queue_overflow);

        StatusType s3{s2};
        
        assert(s3.IsGood() == false);
        assert(s3.IsBad() == true);
        assert(s3.GetBadCode() == StatusType::queue_overflow);

        StatusType s4{std::move(s2)};
        
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.GetBadCode() == StatusType::queue_overflow);
        
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.GetBadCode() == StatusType::good);

        StatusType s5;
        s5 = s3;

        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.GetBadCode() == StatusType::queue_overflow);
        
        StatusType s6;
        s6 = std::move(s3);
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.GetBadCode() == StatusType::queue_overflow);
        
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.GetBadCode() == StatusType::good);

        s6.Reset();
        
        assert(s6.IsGood() == true);
        assert(s6.IsBad() == false);
        assert(s6.GetBadCode() == StatusType::good);
    }
    
        
    return 1;
}