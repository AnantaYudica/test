#ifndef TEST_SYS_SIGNAL_H_DEFN_
#define TEST_SYS_SIGNAL_H_DEFN_

namespace test
{
namespace sys
{

class Signal
{
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
