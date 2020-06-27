#include "test/out/file/Status.h"
#include <cassert>
#include <cstdio>
#include <atomic>
#include <utility>

int main()
{
    using namespace test::out::file;
    {
        typedef Status<std::uint8_t> StatusType;
        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsRequire(StatusType::require_initialize) == false);
        assert(s1.IsRequireInitialize() == false);
        assert(s1.IsStandardOutput() == false);
        assert(s1.IsFileOutput() == false);
        assert(s1.GetBadCode() == StatusType::good);

        StatusType s2;
        auto res = s2.StandardOutput();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsRequire(StatusType::require_initialize) == false);
        assert(s2.IsRequireInitialize() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.GetBadCode() == StatusType::good);
        
        res = s2.FileOutput();

        assert(res == false);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsRequire(StatusType::require_initialize) == false);
        assert(s2.IsRequireInitialize() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.GetBadCode() == StatusType::good);

        StatusType s3;
        
        res = s3.FileOutput();

        assert(res == true);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsRequire(StatusType::require_initialize) == false);
        assert(s3.IsRequireInitialize() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.GetBadCode() == StatusType::good);

        res = s3.StandardOutput();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsRequire(StatusType::require_initialize) == false);
        assert(s3.IsRequireInitialize() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.GetBadCode() == StatusType::good);

        StatusType s4;

        s4.FileOutput();

        res = s4.Bad(StatusType::print_buffer_failed);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsRequire(StatusType::require_initialize) == false);
        assert(s4.IsRequireInitialize() == false);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.GetBadCode() == StatusType::print_buffer_failed);

        res = s4.Bad(StatusType::print_buffer_overflow);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsRequire(StatusType::require_initialize) == false);
        assert(s4.IsRequireInitialize() == false);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.GetBadCode() == StatusType::print_buffer_failed);

        StatusType s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsRequire(StatusType::require_initialize) == false);
        assert(s5.IsRequireInitialize() == false);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == true);
        assert(s5.GetBadCode() == StatusType::print_buffer_failed);

        StatusType s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsRequire(StatusType::require_initialize) == false);
        assert(s6.IsRequireInitialize() == false);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.GetBadCode() == StatusType::print_buffer_failed);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsRequire(StatusType::require_initialize) == false);
        assert(s5.IsRequireInitialize() == false);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == false);
        assert(s5.GetBadCode() == StatusType::good);

        StatusType s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsRequire(StatusType::require_initialize) == false);
        assert(s7.IsRequireInitialize() == false);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == true);
        assert(s7.GetBadCode() == StatusType::print_buffer_failed);
        
        StatusType s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsRequire(StatusType::require_initialize) == false);
        assert(s8.IsRequireInitialize() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == true);
        assert(s8.GetBadCode() == StatusType::print_buffer_failed);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsRequire(StatusType::require_initialize) == false);
        assert(s7.IsRequireInitialize() == false);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == false);
        assert(s7.GetBadCode() == StatusType::good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsRequire(StatusType::require_initialize) == false);
        assert(s8.IsRequireInitialize() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.GetBadCode() == StatusType::good);
        
        s6.Require(StatusType::require_initialize);
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsRequire(StatusType::require_initialize) == true);
        assert(s6.IsRequireInitialize() == true);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.GetBadCode() == StatusType::print_buffer_failed);
        
        s6.Unrequire(StatusType::require_initialize);

        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsRequire(StatusType::require_initialize) == false);
        assert(s6.IsRequireInitialize() == false);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.GetBadCode() == StatusType::print_buffer_failed);

        s8.Require(StatusType::require_initialize);
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsRequire(StatusType::require_initialize) == true);
        assert(s8.IsRequireInitialize() == true);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.GetBadCode() == StatusType::good);
        
        s8.Unrequire(StatusType::require_initialize);
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsRequire(StatusType::require_initialize) == false);
        assert(s8.IsRequireInitialize() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.GetBadCode() == StatusType::good);

        StatusType s9{StatusType::require_initialize | 
            StatusType::standard_output};
        
        assert(s9.IsGood() == true);
        assert(s9.IsBad() == false);
        assert(s9.IsRequire(StatusType::require_initialize) == true);
        assert(s9.IsRequireInitialize() == true);
        assert(s9.IsStandardOutput() == true);
        assert(s9.IsFileOutput() == false);
        assert(s9.GetBadCode() == StatusType::good);
        
        StatusType s10{StatusType::require_initialize | 
            StatusType::standard_output | StatusType::print_buffer_failed};
        
        assert(s10.IsGood() == true);
        assert(s10.IsBad() == false);
        assert(s10.IsRequire(StatusType::require_initialize) == true);
        assert(s10.IsRequireInitialize() == true);
        assert(s10.IsStandardOutput() == true);
        assert(s10.IsFileOutput() == false);
        assert(s10.GetBadCode() == StatusType::good);
    }
    
    {
        typedef Status<std::atomic_uint8_t, std::uint8_t> StatusType;
        const auto good = StatusType::good;
        const auto print_buffer_failed = StatusType::print_buffer_failed;

        StatusType s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsRequire(StatusType::require_initialize) == false);
        assert(s1.IsRequireInitialize() == false);
        assert(s1.IsStandardOutput() == false);
        assert(s1.IsFileOutput() == false);
        assert(s1.GetBadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s2;
        auto res = s2.StandardOutput();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsRequire(StatusType::require_initialize) == false);
        assert(s2.IsRequireInitialize() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.GetBadCode() == good);
        
        res = s2.FileOutput();

        assert(res == false);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsRequire(StatusType::require_initialize) == false);
        assert(s2.IsRequireInitialize() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.GetBadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s3;
        
        res = s3.FileOutput();

        assert(res == true);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsRequire(StatusType::require_initialize) == false);
        assert(s3.IsRequireInitialize() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.GetBadCode() == good);

        res = s3.StandardOutput();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsRequire(StatusType::require_initialize) == false);
        assert(s3.IsRequireInitialize() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.GetBadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s4;

        s4.FileOutput();

        res = s4.Bad(print_buffer_failed);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsRequire(StatusType::require_initialize) == false);
        assert(s4.IsRequireInitialize() == false);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.GetBadCode() == print_buffer_failed);

        res = s4.Bad(Status<std::atomic_uint8_t, std::uint8_t>::print_buffer_overflow);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsRequire(StatusType::require_initialize) == false);
        assert(s4.IsRequireInitialize() == false);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.GetBadCode() == print_buffer_failed);

        Status<std::atomic_uint8_t, std::uint8_t> s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsRequire(StatusType::require_initialize) == false);
        assert(s5.IsRequireInitialize() == false);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == true);
        assert(s5.GetBadCode() == print_buffer_failed);

        Status<std::atomic_uint8_t, std::uint8_t> s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsRequire(StatusType::require_initialize) == false);
        assert(s6.IsRequireInitialize() == false);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.GetBadCode() == print_buffer_failed);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsRequire(StatusType::require_initialize) == false);
        assert(s5.IsRequireInitialize() == false);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == false);
        assert(s5.GetBadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsRequire(StatusType::require_initialize) == false);
        assert(s7.IsRequireInitialize() == false);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == true);
        assert(s7.GetBadCode() == print_buffer_failed);
        
        Status<std::atomic_uint8_t, std::uint8_t> s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsRequire(StatusType::require_initialize) == false);
        assert(s8.IsRequireInitialize() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == true);
        assert(s8.GetBadCode() == print_buffer_failed);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsRequire(StatusType::require_initialize) == false);
        assert(s7.IsRequireInitialize() == false);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == false);
        assert(s7.GetBadCode() == good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsRequire(StatusType::require_initialize) == false);
        assert(s8.IsRequireInitialize() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.GetBadCode() == good);
        
        s6.Require(StatusType::require_initialize);
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsRequire(StatusType::require_initialize) == true);
        assert(s6.IsRequireInitialize() == true);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.GetBadCode() == StatusType::print_buffer_failed);
        
        s6.Unrequire(StatusType::require_initialize);

        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsRequire(StatusType::require_initialize) == false);
        assert(s6.IsRequireInitialize() == false);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.GetBadCode() == StatusType::print_buffer_failed);

        s8.Require(StatusType::require_initialize);
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsRequire(StatusType::require_initialize) == true);
        assert(s8.IsRequireInitialize() == true);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.GetBadCode() == StatusType::good);
        
        s8.Unrequire(StatusType::require_initialize);
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsRequire(StatusType::require_initialize) == false);
        assert(s8.IsRequireInitialize() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.GetBadCode() == StatusType::good);

        StatusType s9{StatusType::require_initialize | 
            StatusType::standard_output};
        
        assert(s9.IsGood() == true);
        assert(s9.IsBad() == false);
        assert(s9.IsRequire(StatusType::require_initialize) == true);
        assert(s9.IsRequireInitialize() == true);
        assert(s9.IsStandardOutput() == true);
        assert(s9.IsFileOutput() == false);
        assert(s9.GetBadCode() == StatusType::good);
        
        StatusType s10{StatusType::require_initialize | 
            StatusType::standard_output | StatusType::print_buffer_failed};
        
        assert(s10.IsGood() == true);
        assert(s10.IsBad() == false);
        assert(s10.IsRequire(StatusType::require_initialize) == true);
        assert(s10.IsRequireInitialize() == true);
        assert(s10.IsStandardOutput() == true);
        assert(s10.IsFileOutput() == false);
        assert(s10.GetBadCode() == StatusType::good);
    }
    

    return 1;
}