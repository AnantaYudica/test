#define TEST_SYS_DEBUG_ENABLE 1
#define TEST_SYS_DEFINITION_DLEVEL 0x02
#include "test/sys/Definition.h"

#include <cstring>
#include <cassert>

int main()
{

    {
        auto now = test::sys::Definition::GetTimestampNow();

        long long year = 1ll * 1000 * 1000 * 60 * 60 * 24 * 31 * 12;
        long long month = 1ll * 1000 * 1000 * 60 * 60 * 24 * 31;
        long long day = 1ll * 1000 * 1000 * 60 * 60 * 24;
        long long hour = 5ll * 1000 * 1000 * 60 * 60;
        long long min = 58ll * 1000 * 1000 * 60;
        long long sec = 31ll * 1000 * 1000;
        long long ms = 521ll * 1000;
        long long micro = 251ll;
        long long n1 = day + hour + min + sec + ms + micro;
        long long n2 = year + month + day + hour + min + sec + ms + micro;
        decltype(now) next = now + n1;
        decltype(now) next2 = now + n2;

        assert(now > 0);

        const auto now_time = test::sys::Definition::GetTime(now);
        const auto next2_time = test::sys::Definition::GetTime(next2);
        const auto now_date = test::sys::Definition::GetDate(now);
        const auto next2_date = test::sys::Definition::GetDate(next2);
        const auto now_dtime = test::sys::Definition::GetDateTime(now);
        const auto next2_dtime = test::sys::Definition::GetDateTime(next2);
        const auto tdur = test::sys::Definition::GetTimeDuration(now, next);

        assert(now_time.Hour != next2_time.Hour);
        assert(now_time.Minute != next2_time.Minute);
        assert(now_time.Second != next2_time.Second);
        assert(now_time.Milisecond != next2_time.Milisecond);
        assert(now_time.Microsecond != next2_time.Microsecond);
        
        assert(now_date.Year != next2_date.Year);
        assert(now_date.Month != next2_date.Month);
        assert(now_date.Weekday != next2_date.Weekday);
        assert(now_date.Day != next2_date.Day);

        assert(next2_time.Hour == next2_dtime.Hour);
        assert(next2_time.Minute == next2_dtime.Minute);
        assert(next2_time.Second == next2_dtime.Second);
        assert(next2_time.Milisecond == next2_dtime.Milisecond);
        assert(next2_time.Microsecond == next2_dtime.Microsecond);
        
        assert(next2_date.Year == next2_dtime.Year);
        assert(next2_date.Month == next2_dtime.Month);
        assert(next2_date.Weekday == next2_dtime.Weekday);
        assert(next2_date.Day == next2_dtime.Day);

        assert(tdur.Day == 1);
        assert(tdur.Hour == 5);
        assert(tdur.Minute == 58);
        assert(tdur.Second == 31);
        assert(tdur.Milisecond == 521);
        assert(tdur.Microsecond == 251);
        
    }
    {
        typedef test::sys::Definition::Status Status;
        const char * cstr = test::sys::Definition::GetStatusName(Status::sOk);
        assert(strncmp(cstr, "sOk", 4) == 0);
        cstr = test::sys::Definition::GetStatusName(Status::sError);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sUnknown", 8) == 0);
        TEST_SYS_INFO("%s", cstr);
        
        cstr = test::sys::Definition::GetStatusName(Status::sAllocationAgumentsFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sAllocationAgumentsFailed", 25) == 0);
        
        cstr = test::sys::Definition::GetStatusName(Status::sUndefined);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sUndefined", 10) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sSignalsAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sSignalsAllocationFailed", 24) == 0);
        
        cstr = test::sys::Definition::GetStatusName(Status::sSignalsReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sSignalsReallocationFailed", 26) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sSignalsReallocationOverflow);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sSignalsReallocationOverflow", 28) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sSignalsReallocationOutOfMemory);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sSignalsReallocationOutOfMemory", 31) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemoryNotClearOnFinalize);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemoryNotClearOnFinalize", 25) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemroyAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemroyAllocationFailed", 23) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemroyReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemroyReallocationFailed", 25) == 0);
        
        cstr = test::sys::Definition::GetStatusName(Status::sMemRecordAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemRecordAllocationFailed", 26) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemRecordDuplicatePointer);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemRecordDuplicatePointer", 26) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemRecordPointerNotFound);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemRecordPointerNotFound", 25) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemRecordSizeOverflow);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemRecordSizeOverflow", 22) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemBlockAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemBlockAllocationFailed", 25) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemBlockReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemBlockReallocationFailed", 27) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemBlockReferenceCountOverflow);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemBlockReferenceCountOverflow", 31) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemPointerCastFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemPointerCastFailed", 21) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemPointerIndexOutOfBounds);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemPointerIndexOutOfBounds", 27) == 0);
        
        cstr = test::sys::Definition::GetStatusName(Status::sMemDummyAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemDummyAllocationFailed", 25) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sMemDummyReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sMemDummyReallocationFailed", 27) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sTaskFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sTaskFailed", 11) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sTaskAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sTaskAllocationFailed", 21) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sBufferAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sBufferAllocationFailed", 23) == 0);
        
        cstr = test::sys::Definition::GetStatusName(Status::sRunnerNullPointer);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sRunnerNullPointer", 18) == 0);

        cstr = test::sys::Definition::GetStatusName(Status::sRunnerAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "sRunnerAllocationFailed", 23) == 0);
    }
    {
        typedef test::sys::Definition::Status Status;
        const char * cstr = test::sys::Definition::GetStatusTagName(Status::sOk);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[System]", 8) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sError);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[System]", 8) == 0);
        
        cstr = test::sys::Definition::GetStatusTagName(Status::sAllocationAgumentsFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[System]", 8) == 0);
        
        cstr = test::sys::Definition::GetStatusTagName(Status::sUndefined);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[System]", 8) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sSignalsAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Signals]", 14) == 0);
        
        cstr = test::sys::Definition::GetStatusTagName(Status::sSignalsReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Signals]", 14) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sSignalsReallocationOverflow);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Signals]", 14) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sSignalsReallocationOutOfMemory);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Signals]", 14) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemoryNotClearOnFinalize);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Memory]", 13) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemroyAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Memory]", 13) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemroyReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Memory]", 13) == 0);
        
        cstr = test::sys::Definition::GetStatusTagName(Status::sMemRecordAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Record]", 18) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemRecordDuplicatePointer);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Record]", 18) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemRecordPointerNotFound);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Record]", 18) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemRecordSizeOverflow);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Record]", 18) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemBlockAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Block]", 17) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemBlockReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Block]", 17) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemBlockReferenceCountOverflow);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Block]", 17) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemPointerCastFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Pointer]", 19) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemPointerIndexOutOfBounds);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][mem][Pointer]", 19) == 0);
        
        cstr = test::sys::Definition::GetStatusTagName(Status::sMemDummyAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys]][mem][Dummy]", 18) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sMemDummyReallocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys]][mem][Dummy]", 18) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sTaskFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Task]", 11) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sTaskAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Task]", 11) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sBufferAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Buffer]", 13) == 0);
        
        cstr = test::sys::Definition::GetStatusTagName(Status::sRunnerNullPointer);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Runner]", 13) == 0);

        cstr = test::sys::Definition::GetStatusTagName(Status::sRunnerAllocationFailed);
        TEST_SYS_INFO("%s", cstr);
        assert(strncmp(cstr, "[sys][Runner]", 13) == 0);
    }
    return 0;
}
