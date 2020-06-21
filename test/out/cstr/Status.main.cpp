#include "test/out/cstr/Status.h"

#include <cassert>

using namespace test::out::cstr;

int main()
{
    Status s1;
    assert(s1.IsGood() == true);
    assert(s1.IsBad() == false);
    assert(s1.IsRequire() == false);
    assert(s1.IsRequireInitialize() == false);
    assert(s1.IsRequireAllocation() == false);
    assert(s1.IsRequireReallocation() == false);
    assert(s1.BadCode() == Status::good);
    assert(s1.IsRequire(Status::require_initialize) == false);
    assert(s1.IsRequire(Status::require_allocation) == false);
    assert(s1.IsRequire(Status::require_reallocation) == false);
    assert(s1.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s1.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == false);
    assert(s1.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == false);
    assert(s1.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == false);

    Status s2;
    s2.Require(Status::require_initialize);
    assert(s2.IsGood() == false);
    assert(s2.IsBad() == false);
    assert(s2.IsRequire() == true);
    assert(s2.IsRequireInitialize() == true);
    assert(s2.IsRequireAllocation() == false);
    assert(s2.IsRequireReallocation() == false);
    assert(s2.BadCode() == Status::good);
    assert(s2.IsRequire(Status::require_initialize) == true);
    assert(s2.IsRequire(Status::require_allocation) == false);
    assert(s2.IsRequire(Status::require_reallocation) == false);
    assert(s2.IsRequire(Status::require_initialize | 
        Status::require_allocation) == true);
    assert(s2.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s2.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == false);
    assert(s2.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    Status s3;
    s3.Require(Status::require_allocation);
    assert(s3.IsGood() == false);
    assert(s3.IsBad() == false);
    assert(s3.IsRequire() == true);
    assert(s3.IsRequireInitialize() == false);
    assert(s3.IsRequireAllocation() == true);
    assert(s3.IsRequireReallocation() == false);
    assert(s3.BadCode() == Status::good);
    assert(s3.IsRequire(Status::require_initialize) == false);
    assert(s3.IsRequire(Status::require_allocation) == true);
    assert(s3.IsRequire(Status::require_reallocation) == false);
    assert(s3.IsRequire(Status::require_initialize | 
        Status::require_allocation) == true);
    assert(s3.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == false);
    assert(s3.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s3.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    Status s4;
    s4.Require(Status::require_reallocation);
    assert(s4.IsGood() == false);
    assert(s4.IsBad() == false);
    assert(s4.IsRequire() == true);
    assert(s4.IsRequireInitialize() == false);
    assert(s4.IsRequireAllocation() == false);
    assert(s4.IsRequireReallocation() == true);
    assert(s4.BadCode() == Status::good);
    assert(s4.IsRequire(Status::require_initialize) == false);
    assert(s4.IsRequire(Status::require_allocation) == false);
    assert(s4.IsRequire(Status::require_reallocation) == true);
    assert(s4.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s4.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s4.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s4.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    Status s5;
    s5.Require(Status::require_initialize | Status::require_allocation);
    assert(s5.IsGood() == false);
    assert(s5.IsBad() == false);
    assert(s5.IsRequire() == true);
    assert(s5.IsRequireInitialize() == true);
    assert(s5.IsRequireAllocation() == true);
    assert(s5.IsRequireReallocation() == false);
    assert(s5.BadCode() == Status::good);
    assert(s5.IsRequire(Status::require_initialize) == true);
    assert(s5.IsRequire(Status::require_allocation) == true);
    assert(s5.IsRequire(Status::require_reallocation) == false);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_allocation) == true);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s5.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);
        
    s5.Unrequire(Status::require_initialize);
    assert(s5.IsGood() == false);
    assert(s5.IsBad() == false);
    assert(s5.IsRequire() == true);
    assert(s5.IsRequireInitialize() == false);
    assert(s5.IsRequireAllocation() == true);
    assert(s5.IsRequireReallocation() == false);
    assert(s5.BadCode() == Status::good);
    assert(s5.IsRequire(Status::require_initialize) == false);
    assert(s5.IsRequire(Status::require_allocation) == true);
    assert(s5.IsRequire(Status::require_reallocation) == false);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_allocation) == true);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == false);
    assert(s5.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    s5.Unrequire(Status::require_allocation);
    assert(s5.IsGood() == true);
    assert(s5.IsBad() == false);
    assert(s5.IsRequire() == false);
    assert(s5.IsRequireInitialize() == false);
    assert(s5.IsRequireAllocation() == false);
    assert(s5.IsRequireReallocation() == false);
    assert(s5.BadCode() == Status::good);
    assert(s5.IsRequire(Status::require_initialize) == false);
    assert(s5.IsRequire(Status::require_allocation) == false);
    assert(s5.IsRequire(Status::require_reallocation) == false);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == false);
    assert(s5.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == false);
    assert(s5.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == false);

    Status s6;
    s6.Bad(Status::copy_reallocation_failed);
    assert(s6.IsGood() == false);
    assert(s6.IsBad() == true);
    assert(s6.IsRequire() == false);
    assert(s6.BadCode() == Status::copy_reallocation_failed);

    Status s7;
    s7.Require(Status::require_reallocation);
    s7.Bad(Status::copy_reallocation_failed);
    assert(s7.IsGood() == false);
    assert(s7.IsBad() == true);
    assert(s7.IsRequire() == true);
    assert(s7.BadCode() == Status::copy_reallocation_failed);
    assert(s7.IsRequire(Status::require_initialize) == false);
    assert(s7.IsRequire(Status::require_allocation) == false);
    assert(s7.IsRequire(Status::require_reallocation) == true);
    assert(s7.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s7.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s7.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s7.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    Status s8{s7};
    assert(s8.IsGood() == false);
    assert(s8.IsBad() == true);
    assert(s8.IsRequire() == true);
    assert(s8.BadCode() == Status::copy_reallocation_failed);
    assert(s8.IsRequire(Status::require_initialize) == false);
    assert(s8.IsRequire(Status::require_allocation) == false);
    assert(s8.IsRequire(Status::require_reallocation) == true);
    assert(s8.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s8.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s8.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s8.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);
        
    Status s9;
    s9 = s7;
    assert(s9.IsGood() == false);
    assert(s9.IsBad() == true);
    assert(s9.IsRequire() == true);
    assert(s9.BadCode() == Status::copy_reallocation_failed);
    assert(s9.IsRequire(Status::require_initialize) == false);
    assert(s9.IsRequire(Status::require_allocation) == false);
    assert(s9.IsRequire(Status::require_reallocation) == true);
    assert(s9.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s9.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s9.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s9.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    Status s10{std::move(s8)};
    assert(s10.IsGood() == false);
    assert(s10.IsBad() == true);
    assert(s10.IsRequire() == true);
    assert(s10.BadCode() == Status::copy_reallocation_failed);
    assert(s10.IsRequire(Status::require_initialize) == false);
    assert(s10.IsRequire(Status::require_allocation) == false);
    assert(s10.IsRequire(Status::require_reallocation) == true);
    assert(s10.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s10.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s10.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s10.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    assert(s8.IsGood() == true);
    assert(s8.IsBad() == false);
    assert(s8.IsRequire() == false);
    assert(s8.IsRequireInitialize() == false);
    assert(s8.IsRequireAllocation() == false);
    assert(s8.IsRequireReallocation() == false);
    assert(s8.BadCode() == Status::good);
    assert(s8.IsRequire(Status::require_initialize) == false);
    assert(s8.IsRequire(Status::require_allocation) == false);
    assert(s8.IsRequire(Status::require_reallocation) == false);
    assert(s8.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s8.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == false);
    assert(s8.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == false);
    assert(s8.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == false);

    Status s11;
    s11 = std::move(s9);
    assert(s11.IsGood() == false);
    assert(s11.IsBad() == true);
    assert(s11.IsRequire() == true);
    assert(s11.BadCode() == Status::copy_reallocation_failed);
    assert(s11.IsRequire(Status::require_initialize) == false);
    assert(s11.IsRequire(Status::require_allocation) == false);
    assert(s11.IsRequire(Status::require_reallocation) == true);
    assert(s11.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s11.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == true);
    assert(s11.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == true);
    assert(s11.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == true);

    assert(s9.IsGood() == true);
    assert(s9.IsBad() == false);
    assert(s9.IsRequire() == false);
    assert(s9.IsRequireInitialize() == false);
    assert(s9.IsRequireAllocation() == false);
    assert(s9.IsRequireReallocation() == false);
    assert(s9.BadCode() == Status::good);
    assert(s9.IsRequire(Status::require_initialize) == false);
    assert(s9.IsRequire(Status::require_allocation) == false);
    assert(s9.IsRequire(Status::require_reallocation) == false);
    assert(s9.IsRequire(Status::require_initialize | 
        Status::require_allocation) == false);
    assert(s9.IsRequire(Status::require_initialize | 
        Status::require_reallocation) == false);
    assert(s9.IsRequire(Status::require_allocation | 
        Status::require_reallocation) == false);
    assert(s9.IsRequire(Status::require_initialize | 
        Status::require_allocation | Status::require_reallocation) == false);

    return 1;
}