#ifndef TEST_SYS_SIGNAL_H_
#define TEST_SYS_SIGNAL_H_

#include "Interface.h"
#include "Signal.defn.h"
#include "../System.h"

namespace test
{

namespace sys
{

inline Signal::Signal()
{
    typedef test::sys::Interface SystemType;
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
    
    System::GetInstance().RegisterSignal(this);
}

inline Signal::~Signal()
{
    typedef test::sys::Interface SystemType;
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    System::GetInstance().UnregisterSignal(this);
}

} //!sys

} //!test

#endif //!TEST_SYS_SIGNAL_H_
