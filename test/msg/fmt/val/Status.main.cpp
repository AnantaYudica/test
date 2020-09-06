#include "test/msg/fmt/val/Status.h"

#include <cassert>
#include <cstdint>
#include <utility>

int main()
{
    using namespace test::msg::fmt::val;
    {
        typedef Status StatusType;
        StatusType s1;
        assert(s1.IsDefaultValue() == false);
        assert(s1.IsSetValue() == false);

        StatusType s2;

        auto res = s2.SetValue();
        assert(res == true);
        assert(s2.IsDefaultValue() == false);
        assert(s2.IsSetValue() == true);

        res = s2.SetValue();
        assert(res == false);
        assert(s2.IsDefaultValue() == false);
        assert(s2.IsSetValue() == true);

        StatusType s3{s2};
        
        assert(s3.IsDefaultValue() == false);
        assert(s3.IsSetValue() == true);

        StatusType s4{std::move(s2)};
        
        assert(s4.IsDefaultValue() == false);
        assert(s4.IsSetValue() == true);
        
        assert(s2.IsDefaultValue() == false);
        assert(s2.IsSetValue() == false);

        StatusType s5;
        s5 = s3;

        assert(s5.IsDefaultValue() == false);
        assert(s5.IsSetValue() == true);
        
        StatusType s6;
        s6 = std::move(s3);
        
        assert(s6.IsDefaultValue() == false);
        assert(s6.IsSetValue() == true);
        
        assert(s3.IsDefaultValue() == false);
        assert(s3.IsSetValue() == false);

        s6.Reset();
        
        assert(s6.IsDefaultValue() == false);
        assert(s6.IsSetValue() == false);

        StatusType s7;
        
        assert(s7.IsDefaultValue() == false);
        assert(s7.IsSetValue() == false);

        s7.UnsetValue();
        
        assert(s7.IsDefaultValue() == false);
        assert(s7.IsSetValue() == false);

        s7.SetValue();
        assert(s7.IsDefaultValue() == false);
        assert(s7.IsSetValue() == true);
        
        s7.UnsetValue();
        assert(s7.IsDefaultValue() == false);
        assert(s7.IsSetValue() == false);

        StatusType s8{StatusType::default_value};
        
        assert(s8.IsDefaultValue() == true);
        assert(s8.IsSetValue() == true);
        
        s8.UnsetValue();
        
        assert(s8.IsDefaultValue() == true);
        assert(s8.IsSetValue() == true);

        StatusType s9(std::move(s8));
        
        assert(s9.IsDefaultValue() == true);
        assert(s9.IsSetValue() == true);
        
        assert(s8.IsDefaultValue() == true);
        assert(s8.IsSetValue() == true);

        StatusType s10;
        s10 = std::move(s9);

        assert(s10.IsDefaultValue() == true);
        assert(s10.IsSetValue() == true);
        
        assert(s9.IsDefaultValue() == true);
        assert(s9.IsSetValue() == true);
    }
    
    return 0;
}