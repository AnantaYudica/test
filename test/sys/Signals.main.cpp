#include "test/sys/Signals.h"
#include "test/System.h"

#include <cassert>

static std::size_t count = 0;

class Derived : public test::sys::Signal
{
public:
    int signal;
public:
    Derived() :
        signal(0)
    {}
public:
    ~Derived()
    {}
public:
    void Termination(int sig) override
    {
        signal = sig;
        ++count;
    }
};

int main()
{
    Derived d1, d2, d3, d4, d5, d6, d7, d8, d9;
    test::sys::Status status;
    test::sys::Log<test::sys::Status> log(status);
    test::sys::Signals<test::sys::Status> signals(status, log);

    assert(signals.Size() == 0);

    signals.Insert(&d1);

    assert(signals.Size() == 1);

    signals.Insert(&d2);
    
    assert(signals.Size() == 2);

    signals.Insert(&d3);
    
    assert(signals.Size() == 3);

    signals.Insert(&d4);
    
    assert(signals.Size() == 4);

    signals.Insert(&d5);
    
    assert(signals.Size() == 5);

    signals.Insert(&d6);
    
    assert(signals.Size() == 6);

    signals.Insert(&d7);
    
    assert(signals.Size() == 7);

    signals.Insert(&d8);
    
    assert(signals.Size() == 8);

    signals.Insert(&d9);
    
    assert(signals.Size() == 9);

    signals.Remove(&d1);
    assert(signals.Size() == 8);

    signals.Remove(&d6);
    assert(signals.Size() == 7);

    signals.Remove(&d9);
    assert(signals.Size() == 6);
    
    signals.Clear();

    assert(signals.Size() == 0);

    signals.Insert(&d2);
    
    assert(signals.Size() == 1);

    signals.Insert(&d3);
    
    assert(signals.Size() == 2);

    signals.Insert(&d4);
    
    assert(signals.Size() == 3);

    signals.Insert(&d5);
    
    assert(signals.Size() == 4);

    signals.Insert(&d6);
    
    assert(signals.Size() == 5);

    signals.Insert(&d8);
    
    assert(signals.Size() == 6);

    signals.Raise(SIGTERM);

    assert(count == 6);
    assert(d1.signal == 0);
    assert(d2.signal == SIGTERM);
    assert(d3.signal == SIGTERM);
    assert(d4.signal == SIGTERM);
    assert(d5.signal == SIGTERM);
    assert(d6.signal == SIGTERM);
    assert(d7.signal == 0);
    assert(d8.signal == SIGTERM);
    assert(d9.signal == 0);

    assert(signals.Size() == 0);

    return 0;
}
