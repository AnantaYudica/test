#include "test/out/base/task/Status.h"

#include <cstdint>
#include <cassert>
#include <utility>
#include <atomic>

int main()
{
    using namespace test::out::base::task;
    {
        typedef Status<std::uint8_t> StatusType;
        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsDone() == false);
        assert(s1.IsRelease() == false);
        assert(s1.IsAssign() == false);
        assert(s1.IsRemove() == false);
        assert(s1.GetBadCode() == StatusType::good);

        StatusType s2;
        auto res = s2.Assign();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == false);
        assert(s2.IsRelease() == false);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == false);
        assert(s2.GetBadCode() == StatusType::good);
        
        res = s2.Release();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == false);
        assert(s2.IsRelease() == true);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == false);
        assert(s2.GetBadCode() == StatusType::good);

        res = s2.Execute();
        
        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == true);
        assert(s2.IsRelease() == true);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == false);
        assert(s2.GetBadCode() == StatusType::good);

        res = s2.Remove();
        
        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == true);
        assert(s2.IsRelease() == true);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == true);
        assert(s2.GetBadCode() == StatusType::good);

        StatusType s3;
        
        res = s3.Release();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsDone() == false);
        assert(s3.IsRelease() == false);
        assert(s3.IsAssign() == false);
        assert(s3.IsRemove() == false);
        assert(s3.GetBadCode() == StatusType::good);
        
        res = s3.Execute();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsDone() == false);
        assert(s3.IsRelease() == false);
        assert(s3.IsAssign() == false);
        assert(s3.IsRemove() == false);
        assert(s3.GetBadCode() == StatusType::good);

        StatusType s4;
        
        res = s4.Assign();

        res = s4.Bad(StatusType::bad);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsDone() == false);
        assert(s4.IsRelease() == false);
        assert(s4.IsAssign() == true);
        assert(s4.IsRemove() == false);
        assert(s4.GetBadCode() == StatusType::bad);

        res = s4.Bad(StatusType::bad);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsDone() == false);
        assert(s4.IsRelease() == false);
        assert(s4.IsAssign() == true);
        assert(s4.IsRemove() == false);
        assert(s4.GetBadCode() == StatusType::bad);

        StatusType s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsDone() == false);
        assert(s5.IsRelease() == false);
        assert(s5.IsAssign() == true);
        assert(s5.IsRemove() == false);
        assert(s5.GetBadCode() == StatusType::bad);

        StatusType s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsDone() == false);
        assert(s6.IsRelease() == false);
        assert(s6.IsAssign() == true);
        assert(s6.IsRemove() == false);
        assert(s6.GetBadCode() == StatusType::bad);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsDone() == false);
        assert(s5.IsRelease() == false);
        assert(s5.IsAssign() == false);
        assert(s5.IsRemove() == false);
        assert(s5.GetBadCode() == StatusType::good);

        StatusType s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsDone() == false);
        assert(s7.IsRelease() == false);
        assert(s7.IsAssign() == true);
        assert(s7.IsRemove() == false);
        assert(s7.GetBadCode() == StatusType::bad);
        
        StatusType s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsDone() == false);
        assert(s8.IsRelease() == false);
        assert(s8.IsAssign() == true);
        assert(s8.IsRemove() == false);
        assert(s8.GetBadCode() == StatusType::bad);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsDone() == false);
        assert(s7.IsRelease() == false);
        assert(s7.IsAssign() == false);
        assert(s7.IsRemove() == false);
        assert(s7.GetBadCode() == StatusType::good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsDone() == false);
        assert(s8.IsRelease() == false);
        assert(s8.IsAssign() == false);
        assert(s8.IsRemove() == false);
        assert(s8.GetBadCode() == StatusType::good);
        
    }
    
    {
        typedef Status<std::atomic_uint8_t, std::uint8_t> StatusType;

        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsDone() == false);
        assert(s1.IsRelease() == false);
        assert(s1.IsAssign() == false);
        assert(s1.IsRemove() == false);
        assert(s1.GetBadCode() == StatusType::good);

        StatusType s2;
        auto res = s2.Assign();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == false);
        assert(s2.IsRelease() == false);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == false);
        assert(s2.GetBadCode() == StatusType::good);
        
        res = s2.Release();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == false);
        assert(s2.IsRelease() == true);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == false);
        assert(s2.GetBadCode() == StatusType::good);

        res = s2.Execute();
        
        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == true);
        assert(s2.IsRelease() == true);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == false);
        assert(s2.GetBadCode() == StatusType::good);

        res = s2.Remove();
        
        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsDone() == true);
        assert(s2.IsRelease() == true);
        assert(s2.IsAssign() == true);
        assert(s2.IsRemove() == true);
        assert(s2.GetBadCode() == StatusType::good);

        StatusType s3;
        
        res = s3.Release();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsDone() == false);
        assert(s3.IsRelease() == false);
        assert(s3.IsAssign() == false);
        assert(s3.IsRemove() == false);
        assert(s3.GetBadCode() == StatusType::good);
        
        res = s3.Execute();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsDone() == false);
        assert(s3.IsRelease() == false);
        assert(s3.IsAssign() == false);
        assert(s3.IsRemove() == false);
        assert(s3.GetBadCode() == StatusType::good);

        StatusType s4;
        
        res = s4.Assign();

        res = s4.Bad(StatusType::bad);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsDone() == false);
        assert(s4.IsRelease() == false);
        assert(s4.IsAssign() == true);
        assert(s4.IsRemove() == false);
        assert(s4.GetBadCode() == StatusType::bad);

        res = s4.Bad(StatusType::bad);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsDone() == false);
        assert(s4.IsRelease() == false);
        assert(s4.IsAssign() == true);
        assert(s4.IsRemove() == false);
        assert(s4.GetBadCode() == StatusType::bad);

        StatusType s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsDone() == false);
        assert(s5.IsRelease() == false);
        assert(s5.IsAssign() == true);
        assert(s5.IsRemove() == false);
        assert(s5.GetBadCode() == StatusType::bad);

        StatusType s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsDone() == false);
        assert(s6.IsRelease() == false);
        assert(s6.IsAssign() == true);
        assert(s6.IsRemove() == false);
        assert(s6.GetBadCode() == StatusType::bad);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsDone() == false);
        assert(s5.IsRelease() == false);
        assert(s5.IsAssign() == false);
        assert(s5.IsRemove() == false);
        assert(s5.GetBadCode() == StatusType::good);

        StatusType s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsDone() == false);
        assert(s7.IsRelease() == false);
        assert(s7.IsAssign() == true);
        assert(s7.IsRemove() == false);
        assert(s7.GetBadCode() == StatusType::bad);
        
        StatusType s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsDone() == false);
        assert(s8.IsRelease() == false);
        assert(s8.IsAssign() == true);
        assert(s8.IsRemove() == false);
        assert(s8.GetBadCode() == StatusType::bad);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsDone() == false);
        assert(s7.IsRelease() == false);
        assert(s7.IsAssign() == false);
        assert(s7.IsRemove() == false);
        assert(s7.GetBadCode() == StatusType::good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsDone() == false);
        assert(s8.IsRelease() == false);
        assert(s8.IsAssign() == false);
        assert(s8.IsRemove() == false);
        assert(s8.GetBadCode() == StatusType::good);
    }
    return 0;
}
