#include "test/out/log/Status.h"

#include <cassert>
#include <utility>

int main()
{
    using namespace test::out::log;
    {
        typedef Status<> StatusType;
        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsBegin() == false);
        assert(s1.IsEnd() == false);
        assert(s1.GetBadCode() == StatusType::good);

        StatusType s2;
        auto res = s2.Begin();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsBegin() == true);
        assert(s2.IsEnd() == false);
        assert(s2.GetBadCode() == StatusType::good);
        
        res = s2.End();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsBegin() == true);
        assert(s2.IsEnd() == true);
        assert(s2.GetBadCode() == StatusType::good);

        StatusType s3;
        
        res = s3.End();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsBegin() == false);
        assert(s3.IsEnd() == false);
        assert(s3.GetBadCode() == StatusType::good);
        
        StatusType s4;
        
        res = s4.Begin();

        res = s4.Bad(StatusType::bad);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsBegin() == true);
        assert(s4.IsEnd() == false);
        assert(s4.GetBadCode() == StatusType::bad);

        res = s4.Bad(StatusType::bad);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsBegin() == true);
        assert(s4.IsEnd() == false);
        assert(s4.GetBadCode() == StatusType::bad);

        StatusType s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsBegin() == true);
        assert(s5.IsEnd() == false);
        assert(s5.GetBadCode() == StatusType::bad);

        StatusType s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsBegin() == true);
        assert(s6.IsEnd() == false);
        assert(s6.GetBadCode() == StatusType::bad);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsBegin() == false);
        assert(s5.IsEnd() == false);
        assert(s5.GetBadCode() == StatusType::good);

        StatusType s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsBegin() == true);
        assert(s7.IsEnd() == false);
        assert(s7.GetBadCode() == StatusType::bad);
        
        StatusType s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsBegin() == true);
        assert(s8.IsEnd() == false);
        assert(s8.GetBadCode() == StatusType::bad);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsBegin() == false);
        assert(s7.IsEnd() == false);
        assert(s7.GetBadCode() == StatusType::good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsBegin() == false);
        assert(s8.IsEnd() == false);
        assert(s8.GetBadCode() == StatusType::good);
        
    }

    return 0;
}