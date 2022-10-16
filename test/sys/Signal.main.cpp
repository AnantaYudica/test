#include "test/sys/Signal.h"

#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cassert>

static int abort_count = 0;

class Derived : public test::sys::Signal
{
public:
    Derived()
    {}
public:
    ~Derived()
    {}
public:
    void Termination(int sig) override
    {
        ++abort_count;
    }
};

int main()
{
    Derived d;
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::raise(SIGTERM);
    }

    assert(abort_count == 1);
    
    return 0;
};