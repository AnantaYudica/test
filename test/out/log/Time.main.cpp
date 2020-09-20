#include "test/out/log/Time.h"

#include <cstdio>
#include <ctime>
#include <chrono>
#include <cassert>

int main()
{
    auto timestamp = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(timestamp);
    auto localtime = std::localtime (&time);
    assert(test::out::log::Time::Year(timestamp) == 
        (1900 + localtime->tm_year));
    assert(test::out::log::Time::Month(timestamp) == 
        (localtime->tm_mon + 1));
    assert(test::out::log::Time::Day(timestamp) == localtime->tm_mday);
    assert(test::out::log::Time::Hour(timestamp) == localtime->tm_hour);
    assert(test::out::log::Time::Minute(timestamp) == localtime->tm_min);
    assert(test::out::log::Time::Second(timestamp) == localtime->tm_sec);
    assert(test::out::log::Time::Millisecond(timestamp) < 1000);
    assert(test::out::log::Time::CStr<char>(timestamp).Size() < 25);
    return 0;
}

