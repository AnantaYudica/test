#ifndef TEST_SYS_SIGNAL_H_
#define TEST_SYS_SIGNAL_H_

#include "Signal.defn.h"
#include "../System.h"

namespace test
{

namespace sys
{

inline Signal::Signal()
{
    System::GetInstance().RegisterSignal(this);
}

inline Signal::~Signal()
{
    System::GetInstance().UnregisterSignal(this);
}

} //!sys

} //!test

#endif //!TEST_SYS_SIGNAL_H_
