#define TEST_SYS_DEBUG_ENABLE 1
#define TEST_SYS_RUNNER_DLEVEL 0x7f
#define TEST_SYS_OUT_INTERFACE_DLEVEL 0x00
#define TEST_SYS_TASK_DLEVEL 0x00
#include "test/sys/Runner.h"
#include "test/sys/Status.h"
#include "test/sys/Buffer.h"
#include "test/sys/Log.h"

#include <ctime>
#include <cstdio>
#include <cassert>
#include <atomic>


const std::size_t Len(const char* str)
{
#ifdef __STDC_LIB_EXT1__
    const std::size_t len = strnlen_s(str, 1024);
#else
    std::size_t len = strlen(str);
#endif
    return len;
}

std::atomic_size_t count{0};

typedef test::sys::Status StatusType;
typedef test::sys::Buffer<StatusType, 128, 1024> BufferType;

int FormatBegin(char* buffer, const std::size_t& buffer_size, 
    test::sys::Task& task)
{
    const auto date_time = test::sys::Definition::
        GetDateTime(task.GetBeginTimeStamp()); 
    return snprintf(buffer, buffer_size, 
        "Begin Task [%04d%02d%02d %02d:%02d:%02d.%03d]", 
        date_time.Year, date_time.Month, date_time.Day, date_time.Hour,
        date_time.Minute, date_time.Second, date_time.Milisecond);
}

int FormatEnd(char* buffer, const std::size_t& buffer_size, 
    test::sys::Task& task)
{
    const auto dur = test::sys::Definition::
        GetTimeDuration(task.GetBeginTimeStamp(),
            task.GetEndTimeStamp()); 
    if (dur.Day != 0)
    {
        return snprintf(buffer, buffer_size, "End Task "
            "[%d Days %02d:%02d:%02d.%03d]",
            dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond);
    }
    else
    {
        return snprintf(buffer, buffer_size, "End Task "
            "[%02d:%02d:%02d.%03d]",
            dur.Hour, dur.Minute, dur.Second, dur.Milisecond);
    }
}

int FormatAssert(char* buffer, const std::size_t& buffer_size, 
    test::sys::Task& task, const char* cond_str,
    const char* file, const int& line, const char* variables)
{
    return snprintf(buffer, buffer_size, "Assert Condition (%s) file %s "
        "line %zu info %s", 
        cond_str, file, line, variables);
}

struct Test
{
    StatusType status;
    test::sys::Log<StatusType> output;
    test::sys::Buffer<StatusType, 128, 1024> buff_1;
    test::sys::Buffer<StatusType, 128, 1024> buff_2;
    test::sys::Buffer<StatusType, 128, 1024> buff_4;
    test::sys::Buffer<StatusType, 128, 1024> buff_16;
    test::sys::Buffer<StatusType, 128, 1024> buff_32;
    test::sys::Runner<StatusType, BufferType, 0> r0;
    test::sys::Runner<StatusType, BufferType, 0> r0_1;
    test::sys::Runner<StatusType, BufferType, 1> r1;
    test::sys::Runner<StatusType, BufferType, 1> r1_1;
    test::sys::Runner<StatusType, BufferType, 2> r2;
    test::sys::Runner<StatusType, BufferType, 2> r2_1;
    test::sys::Runner<StatusType, BufferType, 4> r4;
    test::sys::Runner<StatusType, BufferType, 4> r4_1;
    test::sys::Runner<StatusType, BufferType, 16> r16;
    test::sys::Runner<StatusType, BufferType, 16> r16_1;
    test::sys::Runner<StatusType, BufferType, 32> r32;
    test::sys::Runner<StatusType, BufferType, 32> r32_1;
    Test() :
        status{},
        output(status),
        buff_1(status),
        buff_2(status),
        buff_4(status),
        buff_16(status),
        buff_32(status),
        r0{status, output},
        r0_1{status, output},
        r1{status, output},
        r1_1{status, buff_1},
        r2{status, output},
        r2_1{status, buff_2},
        r4{status, output},
        r4_1{status, buff_4},
        r16{status, output},
        r16_1{status, buff_16},
        r32{status, output},
        r32_1{status, buff_32}
    {}

};

std::atomic_int test_seq(0);

class Interface1 :
    public test::sys::Interface
{
private:
    Test& t;
public:
    Interface1(Test& t) :
        test::sys::Interface(),
        t(t)
    {
        test::sys::Interface::SetInstance(this);
    }

    inline int VOutput(const std::size_t& thread_hid,
        const char * prefix, const char* format, va_list args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 4, 0)))
    {
        const std::size_t main_hid = test::sys::Definition::GetMainThreadHID();
        char buffer[1025];
        char msg[1025];
        int res = vsnprintf(buffer, 1024, format, args);
        buffer[1024] = '\0';
        res += snprintf(msg, 1024, "%s: %s", prefix, buffer);
        msg[1024] = '\0';

        if (main_hid == thread_hid)
        {
            return t.output.Output("%s", msg);
        }
        if (test_seq.load() == 0)
        {
            t.r0.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res; 
        }
        else if (test_seq.load() == 1)
        {
            
            t.r0_1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res; 
        }
        else if(test_seq.load() == 10)
        {
            t.r1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 11)
        {
            t.r1_1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 20)
        {
            t.r2.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 21)
        {
            t.r2_1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 40)
        {
            t.r4.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 41)
        {
            t.r4_1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 160)
        {
            t.r16.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 161)
        {
            t.r16_1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 320)
        {
            t.r32.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else if(test_seq.load() == 321)
        {
            t.r32_1.LogBufferOutput(test::sys::Definition::GetThisThreadHID(),
                msg);
            return res;
        }
        else
        {
           return t.output.Output("%s", msg);
        }
    }
};

TEST_SYS_DBG_TYPE_DEFINE("Interface1", Interface1);


int main()
{
    constexpr std::size_t wait = 6000;
    std::srand(std::time(nullptr));
    Test tobj;
    Interface1 interface1(tobj);

    TEST_SYS_INFO("wait init");
    std::this_thread::sleep_for(std::chrono::seconds(4));


    TEST_SYS_INFO("-- start test seq 0 0---");
    test_seq.store(0);
    tobj.r0.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r0.SetEndTaskFormatCallback(FormatEnd);
    tobj.r0.SetAssertTaskFormatCallback(FormatAssert);
    assert(tobj.r0.IdleCount() == 0);
    assert(tobj.r0.RunCount() == 0);
    {
        for (std::size_t i = 0; i < 10; ++i)
        {
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("test-r0-%zu", count.load());
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r0.Job(std::move(t));
        }
        tobj.r0.Stop();
        assert(count.load() == 10);
        for (std::size_t i = 0; i < 10; ++i)
        {
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r0.Job(std::move(t));
        }
        assert(count.load() == 10);
    }
    TEST_SYS_INFO("wait");
    std::this_thread::sleep_for(std::chrono::seconds(4));
    
    TEST_SYS_INFO("-- start test seq 0 1---");
    test_seq.store(1);
    
    tobj.r0_1.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r0_1.SetEndTaskFormatCallback(FormatEnd);
    tobj.r0_1.SetAssertTaskFormatCallback(FormatAssert);
    {
        test::sys::Task t{"test"};
        t.Main([](test::sys::Task& task){
            TEST_SYS_INFO("test-r0_1-0");
            const auto random = (std::rand() % 900) + 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(random));
            task.Assert(true, "true", __FILE__, __LINE__, "test-true");
            task.Assert(false, "false", __FILE__, __LINE__, "test-false");
        });
        tobj.r0_1.Job(std::move(t));
    }

    std::this_thread::sleep_for(std::chrono::seconds(4));

    TEST_SYS_INFO("-- start test seq 10 + 0 ---");
    test_seq.store(10);
    tobj.r1.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r1.SetEndTaskFormatCallback(FormatEnd);
    tobj.r1.SetAssertTaskFormatCallback(FormatAssert);
    {
        for (std::size_t i = 0; i < 10; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check~");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r1.Job(std::move(t));
        }
        do
        {
            TEST_SYS_INFO("wait1");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } while(tobj.r1.IdleCount() != 1 || tobj.r1.RunCount() != 0 ||
            tobj.r1.QueueSize() != 1);
        tobj.r1.Stop();
        assert(count.load() == 20);
        for (std::size_t i = 0; i < 10; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r1.Job(std::move(t));
        }
        assert(count.load() == 20);
    }

    TEST_SYS_INFO("-- start test seq 10 + 1 ---");
    test_seq.store(11);
    tobj.r1_1.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r1_1.SetEndTaskFormatCallback(FormatEnd);
    tobj.r1_1.SetAssertTaskFormatCallback(FormatAssert);
    {
        for (std::size_t i = 0; i < 10; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check %zu", task.GetThreadHID());
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r1_1.Job(std::move(t));
        }

        test::sys::Task t{"test"};
        t.Main([](test::sys::Task& task){
            TEST_SYS_INFO("check 1234");
            TEST_SYS_INFO("check 5678");
            TEST_SYS_INFO("check 9011");
            TEST_SYS_INFO("check 1213");
            TEST_SYS_INFO("check 1415");
            const auto random = (std::rand() % 900) + 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(random));
            task.Assert(true, "true", __FILE__, __LINE__, "test-true");
            task.Assert(false, "false", __FILE__, __LINE__, "test-false");
        });
        tobj.r1_1.Job(std::move(t));

        while(!tobj.r1_1.IsStop())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for (std::size_t i = 0; i < tobj.buff_1.Size(); ++i)
        {
            TEST_SYS_INFO("%s", tobj.buff_1[i].GetMessage());
        }

        assert(tobj.buff_1.Size() == 6);
        int len1 = Len(tobj.buff_1[0].GetMessage());
        constexpr std::size_t n = sizeof("check 1234") - 1;
        auto& buff = tobj.buff_1;
        assert(strncmp(buff[0].GetMessage() + (len1 - n), 
            "check 1234", 1024) == 0);
        assert(strncmp(buff[1].GetMessage() + (len1 - n), 
            "check 5678", 1024) == 0);
        assert(strncmp(buff[2].GetMessage() + (len1 - n), 
            "check 9011", 1024) == 0);
        assert(strncmp(buff[3].GetMessage() + (len1 - n), 
            "check 1213", 1024) == 0);
        assert(strncmp(buff[4].GetMessage() + (len1 - n), 
            "check 1415", 1024) == 0);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(wait));

    TEST_SYS_INFO("-- start test seq 20 + 0 ---");
    test_seq.store(20);
    tobj.r2.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r2.SetEndTaskFormatCallback(FormatEnd);
    tobj.r2.SetAssertTaskFormatCallback(FormatAssert);
    {
        for (std::size_t i = 0; i < 20; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r2.Job(std::move(t));
        }
        tobj.r2.WaitAndStop();
        TEST_SYS_INFO("%zu %zu %zu", count.load(), tobj.r2.RunCount(), tobj.r2.IdleCount());
        assert(count.load() == 40);
        for (std::size_t i = 0; i < 20; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r2.Job(std::move(t));
        }
        assert(count.load() == 40);
    }
    
    TEST_SYS_INFO("-- start test seq 20 + 1 ---");
    test_seq.store(21);
    tobj.r2_1.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r2_1.SetEndTaskFormatCallback(FormatEnd);
    {
        for (std::size_t i = 0; i < 20; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r2_1.Job(std::move(t));
        }
        test::sys::Task t{"test"};
        t.Main([](test::sys::Task& task){
            TEST_SYS_INFO("check 1");
            TEST_SYS_INFO("check 2");
            TEST_SYS_INFO("check 3");
            TEST_SYS_INFO("check 4");
            TEST_SYS_INFO("check 5");
            TEST_SYS_INFO("check 6");
            TEST_SYS_INFO("check 7");
            TEST_SYS_INFO("check 8");
            TEST_SYS_INFO("check 9");
            TEST_SYS_INFO("check 0");
            const auto random = (std::rand() % 900) + 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(random));
            task.Assert(true, "true", __FILE__, __LINE__, "test-true");
            task.Assert(false, "false", __FILE__, __LINE__, "test-false");
        });
        tobj.r2_1.Job(std::move(t));
        
        while(!tobj.r2_1.IsStop())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for (std::size_t i = 0; i < tobj.buff_2.Size(); ++i)
        {
            TEST_SYS_INFO("%s", tobj.buff_2[i].GetMessage());
        }

        assert(tobj.buff_2.Size() == 11);
        int len1 = Len(tobj.buff_2[0].GetMessage());
        constexpr std::size_t n = sizeof("check 1") - 1;
        auto& buff = tobj.buff_2;
        assert(strncmp(buff[0].GetMessage() + (len1 - n), 
            "check 1", 1024) == 0);
        assert(strncmp(buff[1].GetMessage() + (len1 - n), 
            "check 2", 1024) == 0);
        assert(strncmp(buff[2].GetMessage() + (len1 - n), 
            "check 3", 1024) == 0);
        assert(strncmp(buff[3].GetMessage() + (len1 - n), 
            "check 4", 1024) == 0);
        assert(strncmp(buff[4].GetMessage() + (len1 - n), 
            "check 5", 1024) == 0);
        assert(strncmp(buff[5].GetMessage() + (len1 - n), 
            "check 6", 1024) == 0);
        assert(strncmp(buff[6].GetMessage() + (len1 - n), 
            "check 7", 1024) == 0);
        assert(strncmp(buff[7].GetMessage() + (len1 - n), 
            "check 8", 1024) == 0);
        assert(strncmp(buff[8].GetMessage() + (len1 - n), 
            "check 9", 1024) == 0);
        assert(strncmp(buff[9].GetMessage() + (len1 - n), 
            "check 0", 1024) == 0);
    }

    
    std::this_thread::sleep_for(std::chrono::milliseconds(wait));


    TEST_SYS_INFO("-- start test seq 40 + 0 ---");
    test_seq.store(40);
    tobj.r4.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r4.SetEndTaskFormatCallback(FormatEnd);
    tobj.r4.SetAssertTaskFormatCallback(FormatAssert);
    {
        for (std::size_t i = 0; i < 40; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r4.Job(std::move(t));
        }
        tobj.r4.WaitAndStop();
        assert(count.load() == 80);
        for (std::size_t i = 0; i < 20; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r4.Job(std::move(t));
        }
        assert(count.load() == 80);
    }
    
    TEST_SYS_INFO("-- start test seq 40 + 1 ---");
    test_seq.store(41);
    {
        for (std::size_t i = 0; i < 40; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r4_1.Job(std::move(t));
        }
        test::sys::Task t{"test"};
        t.Main([](test::sys::Task& task){
            TEST_SYS_INFO("1234");
            TEST_SYS_INFO("5678");
            TEST_SYS_INFO("9011");
            TEST_SYS_INFO("1213");
            TEST_SYS_INFO("1415");
            TEST_SYS_INFO("1617");
            TEST_SYS_INFO("1819");
            TEST_SYS_INFO("2021");
            TEST_SYS_INFO("2223");
            TEST_SYS_INFO("2425");
            TEST_SYS_INFO("2627");
            const auto random = (std::rand() % 900) + 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(random));
            task.Assert(true, "true", __FILE__, __LINE__, "test-true");
            task.Assert(false, "false", __FILE__, __LINE__, "test-false");
        });
        tobj.r4_1.Job(std::move(t));
        
        while(!tobj.r4_1.IsStop())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for (std::size_t i = 0; i < tobj.buff_4.Size(); ++i)
        {
            TEST_SYS_INFO("%s", tobj.buff_4[i].GetMessage());
        }

        assert(tobj.buff_4.Size() == 12);
        int len1 = Len(tobj.buff_4[0].GetMessage());
        constexpr std::size_t n = sizeof("1234") - 1;
        auto& buff = tobj.buff_4;
        assert(strncmp(buff[0].GetMessage() + (len1 - n), 
            "1234", 1024) == 0);
        assert(strncmp(buff[1].GetMessage() + (len1 - n), 
            "5678", 1024) == 0);
        assert(strncmp(buff[2].GetMessage() + (len1 - n), 
            "9011", 1024) == 0);
        assert(strncmp(buff[3].GetMessage() + (len1 - n), 
            "1213", 1024) == 0);
        assert(strncmp(buff[4].GetMessage() + (len1 - n), 
            "1415", 1024) == 0);
        assert(strncmp(buff[5].GetMessage() + (len1 - n), 
            "1617", 1024) == 0);
        assert(strncmp(buff[6].GetMessage() + (len1 - n), 
            "1819", 1024) == 0);
        assert(strncmp(buff[7].GetMessage() + (len1 - n), 
            "2021", 1024) == 0);
        assert(strncmp(buff[8].GetMessage() + (len1 - n), 
            "2223", 1024) == 0);
        assert(strncmp(buff[9].GetMessage() + (len1 - n), 
            "2425", 1024) == 0);
        assert(strncmp(buff[10].GetMessage() + (len1 - n), 
            "2627", 1024) == 0);
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(wait));
    
    TEST_SYS_INFO("-- start test seq 160 + 0 ---");
    test_seq.store(160);
    tobj.r16.SetBeginTaskFormatCallback(FormatBegin);
    tobj.r16.SetEndTaskFormatCallback(FormatEnd);
    tobj.r16.SetAssertTaskFormatCallback(FormatAssert);
    {
        for (std::size_t i = 0; i < 80; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r16.Job(std::move(t));
        }
        tobj.r16.WaitAndStop();
    }
    
    TEST_SYS_INFO("-- start test seq 160 + 1 ---");
    test_seq.store(161);
    {
        for (std::size_t i = 0; i < 160; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r16_1.Job(std::move(t));
        }
        test::sys::Task t{"test"};
        t.Main([](test::sys::Task& task){
            TEST_SYS_INFO("1234");
            TEST_SYS_INFO("5678");
            TEST_SYS_INFO("9011");
            TEST_SYS_INFO("1213");
            TEST_SYS_INFO("1415");
            TEST_SYS_INFO("1617");
            TEST_SYS_INFO("1819");
            TEST_SYS_INFO("2021");
            TEST_SYS_INFO("2223");
            TEST_SYS_INFO("2425");
            TEST_SYS_INFO("2627");
            const auto random = (std::rand() % 900) + 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(random));
            task.Assert(true, "true", __FILE__, __LINE__, "test-true");
            task.Assert(false, "false", __FILE__, __LINE__, "test-false");
        });
        tobj.r16_1.Job(std::move(t));
        
        while(!tobj.r16_1.IsStop())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for (std::size_t i = 0; i < tobj.buff_16.Size(); ++i)
        {
            TEST_SYS_INFO("%s", tobj.buff_16[i].GetMessage());
        }

        assert(tobj.buff_16.Size() == 12);
        int len1 = Len(tobj.buff_16[0].GetMessage());
        constexpr std::size_t n = sizeof("1234") - 1;
        auto& buff = tobj.buff_16;
        assert(strncmp(buff[0].GetMessage() + (len1 - n), 
            "1234", 1024) == 0);
        assert(strncmp(buff[1].GetMessage() + (len1 - n), 
            "5678", 1024) == 0);
        assert(strncmp(buff[2].GetMessage() + (len1 - n), 
            "9011", 1024) == 0);
        assert(strncmp(buff[3].GetMessage() + (len1 - n), 
            "1213", 1024) == 0);
        assert(strncmp(buff[4].GetMessage() + (len1 - n), 
            "1415", 1024) == 0);
        assert(strncmp(buff[5].GetMessage() + (len1 - n), 
            "1617", 1024) == 0);
        assert(strncmp(buff[6].GetMessage() + (len1 - n), 
            "1819", 1024) == 0);
        assert(strncmp(buff[7].GetMessage() + (len1 - n), 
            "2021", 1024) == 0);
        assert(strncmp(buff[8].GetMessage() + (len1 - n), 
            "2223", 1024) == 0);
        assert(strncmp(buff[9].GetMessage() + (len1 - n), 
            "2425", 1024) == 0);
        assert(strncmp(buff[10].GetMessage() + (len1 - n), 
            "2627", 1024) == 0);
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(wait));

    TEST_SYS_INFO("-- start test seq 320 + 0 ---");
    test_seq.store(320);
    {
        for (std::size_t i = 0; i < 80; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                count++;
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r32.Job(std::move(t));
        }
        tobj.r32.WaitAndStop();
    }
    
    TEST_SYS_INFO("-- start test seq 320 + 1 ---");
    test_seq.store(321);
    {
        for (std::size_t i = 0; i < 320; ++i)
        {
            TEST_SYS_INFO("int i %zu", i);
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("check");
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            tobj.r32_1.Job(std::move(t));
        }
        test::sys::Task t{"test"};
        t.Main([](test::sys::Task& task){
            TEST_SYS_INFO("1234");
            TEST_SYS_INFO("5678");
            TEST_SYS_INFO("9011");
            TEST_SYS_INFO("1213");
            TEST_SYS_INFO("1415");
            TEST_SYS_INFO("1617");
            TEST_SYS_INFO("1819");
            TEST_SYS_INFO("2021");
            TEST_SYS_INFO("2223");
            TEST_SYS_INFO("2425");
            TEST_SYS_INFO("2627");
            const auto random = (std::rand() % 900) + 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(random));
            task.Assert(true, "true", __FILE__, __LINE__, "test-true");
            task.Assert(false, "false", __FILE__, __LINE__, "test-false");
        });
        tobj.r32_1.Job(std::move(t));
        
        while(!tobj.r32_1.IsStop())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for (std::size_t i = 0; i < tobj.buff_32.Size(); ++i)
        {
            TEST_SYS_INFO("%s", tobj.buff_32[i].GetMessage());
        }

        assert(tobj.buff_32.Size() == 12);
        int len1 = Len(tobj.buff_32[0].GetMessage());
        constexpr std::size_t n = sizeof("1234") - 1;
        auto& buff = tobj.buff_32;
        assert(strncmp(buff[0].GetMessage() + (len1 - n), 
            "1234", 1024) == 0);
        assert(strncmp(buff[1].GetMessage() + (len1 - n), 
            "5678", 1024) == 0);
        assert(strncmp(buff[2].GetMessage() + (len1 - n), 
            "9011", 1024) == 0);
        assert(strncmp(buff[3].GetMessage() + (len1 - n), 
            "1213", 1024) == 0);
        assert(strncmp(buff[4].GetMessage() + (len1 - n), 
            "1415", 1024) == 0);
        assert(strncmp(buff[5].GetMessage() + (len1 - n), 
            "1617", 1024) == 0);
        assert(strncmp(buff[6].GetMessage() + (len1 - n), 
            "1819", 1024) == 0);
        assert(strncmp(buff[7].GetMessage() + (len1 - n), 
            "2021", 1024) == 0);
        assert(strncmp(buff[8].GetMessage() + (len1 - n), 
            "2223", 1024) == 0);
        assert(strncmp(buff[9].GetMessage() + (len1 - n), 
            "2425", 1024) == 0);
        assert(strncmp(buff[10].GetMessage() + (len1 - n), 
            "2627", 1024) == 0);
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(wait));

    TEST_SYS_INFO("%d", count.load());

    return 0;
}
