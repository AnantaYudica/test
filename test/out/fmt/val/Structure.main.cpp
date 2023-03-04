#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_OUT_FMT_VAL_STRUCTURE_DLEVEL 0x7f

#include "test/out/fmt/val/Structure.h"
#include "test/out/fmt/Status.h"

#include <cassert>
#include <cstdint>

int main()
{
    typedef test::out::fmt::val::Structure<test::out::fmt::Status> 
        StructureType;
    StructureType s1;

    assert(s1.m_status.IsBad() == true);
    assert(s1.m_status.IsGood() == false);
    assert(s1.m_loadSize == 0);
    assert(s1.m_blocks == nullptr);
    assert(s1.m_raw == nullptr);

    s1.m_blocks = StructureType::BlocksType(test::ptr::arg::Array{2});
    s1.m_raw = StructureType::RawType(test::ptr::arg::Array{4});
    
    assert(s1.m_blocks != nullptr);
    assert(s1.m_raw != nullptr);

    return 0;
}
