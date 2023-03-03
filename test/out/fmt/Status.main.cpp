#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_OUT_FMT_STATUS_DLEVEL 0x7f

#include "test/out/fmt/Status.h"

#include <cassert>
#include <cstdint>

int main()
{
    {
        test::out::fmt::Status s1;

        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.value_not_set);

        assert(s1.Bad(s1.load_failed) == true);
        
        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.load_failed);

        
        assert(s1.Bad(s1.load_failed) == false);
        
        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.load_failed);

        s1.Reset();
        
        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.value_not_set);
        
        assert(s1.Bad(s1.good) == true);
        
        assert(s1.IsBad() == false);
        assert(s1.IsGood() == true);
        assert(s1.GetBadCode() == s1.good);
    }
    {
        test::out::fmt::Status s1;

        assert(s1.Bad(s1.load_failed) == true);

        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.load_failed);
        
        test::out::fmt::Status s2{s1};
        
        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.load_failed);
        
        assert(s2.IsBad() == true);
        assert(s2.IsGood() == false);
        assert(s2.GetBadCode() == s1.load_failed);
        
        test::out::fmt::Status s3;

        s3 = s1;
        
        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.load_failed);
        
        assert(s3.IsBad() == true);
        assert(s3.IsGood() == false);
        assert(s3.GetBadCode() == s1.load_failed);
        
    }
    
    {
        test::out::fmt::Status s1;

        assert(s1.Bad(s1.load_failed) == true);

        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.load_failed);
        
        test::out::fmt::Status s2{std::move(s1)};
        
        assert(s1.IsBad() == true);
        assert(s1.IsGood() == false);
        assert(s1.GetBadCode() == s1.value_not_set);
        
        assert(s2.IsBad() == true);
        assert(s2.IsGood() == false);
        assert(s2.GetBadCode() == s1.load_failed);
        
        test::out::fmt::Status s3;

        s3 = std::move(s2);
        
        assert(s2.IsBad() == true);
        assert(s2.IsGood() == false);
        assert(s2.GetBadCode() == s1.value_not_set);
        
        assert(s3.IsBad() == true);
        assert(s3.IsGood() == false);
        assert(s3.GetBadCode() == s1.load_failed);
        
    }
    return 0;
}
