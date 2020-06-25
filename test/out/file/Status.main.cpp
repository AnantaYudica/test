#include "test/out/file/Status.h"
#include <cassert>
#include <cstdio>
#include <atomic>
#include <utility>

int main()
{
    using namespace test::out::file;
    {
        Status<std::uint8_t> s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsStandardOutput() == false);
        assert(s1.IsFileOutput() == false);
        assert(s1.BadCode() == Status<std::uint8_t>::good);

        Status<std::uint8_t> s2;
        auto res = s2.StandardOutput();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.BadCode() == Status<std::uint8_t>::good);
        
        res = s2.FileOutput();

        assert(res == false);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.BadCode() == Status<std::uint8_t>::good);

        Status<std::uint8_t> s3;
        
        res = s3.FileOutput();

        assert(res == true);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.BadCode() == Status<std::uint8_t>::good);

        res = s3.StandardOutput();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.BadCode() == Status<std::uint8_t>::good);

        Status<std::uint8_t> s4;

        s4.FileOutput();

        res = s4.Bad(Status<std::uint8_t>::print_buffer_failed);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.BadCode() == Status<std::uint8_t>::print_buffer_failed);

        res = s4.Bad(Status<std::uint8_t>::print_buffer_overflow);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.BadCode() == Status<std::uint8_t>::print_buffer_failed);

        Status<std::uint8_t> s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == true);
        assert(s5.BadCode() == Status<std::uint8_t>::print_buffer_failed);

        Status<std::uint8_t> s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.BadCode() == Status<std::uint8_t>::print_buffer_failed);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == false);
        assert(s5.BadCode() == Status<std::uint8_t>::good);

        Status<std::uint8_t> s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == true);
        assert(s7.BadCode() == Status<std::uint8_t>::print_buffer_failed);
        
        Status<std::uint8_t> s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == true);
        assert(s8.BadCode() == Status<std::uint8_t>::print_buffer_failed);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == false);
        assert(s7.BadCode() == Status<std::uint8_t>::good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.BadCode() == Status<std::uint8_t>::good);
    }
    
    {
        const auto good = Status<std::atomic_uint8_t, std::uint8_t>::good;
        const auto print_buffer_failed =
            Status<std::atomic_uint8_t, std::uint8_t>::print_buffer_failed;

        Status<std::atomic_uint8_t, std::uint8_t> s1;
        assert(s1.IsGood() == true);
        assert(s1.IsBad() == false);
        assert(s1.IsStandardOutput() == false);
        assert(s1.IsFileOutput() == false);
        assert(s1.BadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s2;
        auto res = s2.StandardOutput();

        assert(res == true);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.BadCode() == good);
        
        res = s2.FileOutput();

        assert(res == false);
        assert(s2.IsGood() == true);
        assert(s2.IsBad() == false);
        assert(s2.IsStandardOutput() == true);
        assert(s2.IsFileOutput() == false);
        assert(s2.BadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s3;
        
        res = s3.FileOutput();

        assert(res == true);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.BadCode() == good);

        res = s3.StandardOutput();

        assert(res == false);
        assert(s3.IsGood() == true);
        assert(s3.IsBad() == false);
        assert(s3.IsStandardOutput() == false);
        assert(s3.IsFileOutput() == true);
        assert(s3.BadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s4;

        s4.FileOutput();

        res = s4.Bad(print_buffer_failed);

        assert(res == true);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.BadCode() == print_buffer_failed);

        res = s4.Bad(Status<std::atomic_uint8_t, std::uint8_t>::print_buffer_overflow);

        assert(res == false);
        assert(s4.IsGood() == false);
        assert(s4.IsBad() == true);
        assert(s4.IsStandardOutput() == false);
        assert(s4.IsFileOutput() == true);
        assert(s4.BadCode() == print_buffer_failed);

        Status<std::atomic_uint8_t, std::uint8_t> s5{s4};
        
        assert(s5.IsGood() == false);
        assert(s5.IsBad() == true);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == true);
        assert(s5.BadCode() == print_buffer_failed);

        Status<std::atomic_uint8_t, std::uint8_t> s6{std::move(s5)};
        
        assert(s6.IsGood() == false);
        assert(s6.IsBad() == true);
        assert(s6.IsStandardOutput() == false);
        assert(s6.IsFileOutput() == true);
        assert(s6.BadCode() == print_buffer_failed);
        
        assert(s5.IsGood() == true);
        assert(s5.IsBad() == false);
        assert(s5.IsStandardOutput() == false);
        assert(s5.IsFileOutput() == false);
        assert(s5.BadCode() == good);

        Status<std::atomic_uint8_t, std::uint8_t> s7;
        s7 = s6;

        assert(s7.IsGood() == false);
        assert(s7.IsBad() == true);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == true);
        assert(s7.BadCode() == print_buffer_failed);
        
        Status<std::atomic_uint8_t, std::uint8_t> s8;
        s8 = std::move(s7);
        
        assert(s8.IsGood() == false);
        assert(s8.IsBad() == true);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == true);
        assert(s8.BadCode() == print_buffer_failed);
        
        assert(s7.IsGood() == true);
        assert(s7.IsBad() == false);
        assert(s7.IsStandardOutput() == false);
        assert(s7.IsFileOutput() == false);
        assert(s7.BadCode() == good);

        s8.Reset();
        
        assert(s8.IsGood() == true);
        assert(s8.IsBad() == false);
        assert(s8.IsStandardOutput() == false);
        assert(s8.IsFileOutput() == false);
        assert(s8.BadCode() == good);
    }
    

    return 1;
}