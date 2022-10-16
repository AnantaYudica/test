#include "test/sys/Definition.h"

#include <cassert>

int main()
{

    {
        auto now = test::sys::Definition::GetTimestampNow();

        long long year = 1ll * 1000 * 1000 * 60 * 60 * 24 * 30 * 12;
        long long month = 1ll * 1000 * 1000 * 60 * 60 * 24 * 30;
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
    return 0;
}
