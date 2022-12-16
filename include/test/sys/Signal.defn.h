#ifndef TEST_SYS_SIGNAL_H_DEFN_
#define TEST_SYS_SIGNAL_H_DEFN_

#include "Definition.h"
#include "Debug.h"

namespace test::sys
{
class Signal;
}

#ifndef TEST_SYS_SIGNAL_DLEVEL

#define TEST_SYS_SIGNAL_DLEVEL 2

#endif //!TEST_SYS_SIGNAL_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_SYS_SIGNAL_DLEVEL, 
    "test::sys::Signal", test::sys::Signal);

namespace test
{
namespace sys
{

class Signal
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::dbg::Type<test::sys::Signal> DebugType;
protected:
    inline Signal();
public:
    virtual inline ~Signal();
public:
    virtual inline void Termination(int sig) = 0;
};

} //!sys

} //!test

#endif //!TEST_SYS_SIGNAL_H_DEFN_
