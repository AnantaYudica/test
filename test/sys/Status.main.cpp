#include "test/sys/Status.h"

#include <cassert>
#include <cstring>

int main()
{
    test::sys::Status status;
    assert(status.IsStart() == false);
    assert(status.IsEnd() == false);
    assert(status.IsError() == false);
    assert(status.IsTerminate() == false);

    status.Start();
    assert(status.IsStart() == true);
    assert(status.IsEnd() == false);
    assert(status.IsError() == false);
    assert(status.IsTerminate() == false);

    assert(status.GetStartTimestamp() != 0);

    status.Error(1);
    assert(status.IsStart() == true);
    assert(status.IsEnd() == false);
    assert(status.IsError() == true);
    assert(status.IsTerminate() == false);

    assert(status.GetTerminationTimestamp() != 0); 
    assert(status.GetErrorCode() == 1);
    assert(strncmp(status.GetErrorName(), "sOk", 3) != 0);

    status.Termination(1);
    assert(status.IsStart() == true);
    assert(status.IsEnd() == false);
    assert(status.IsError() == true);
    assert(status.IsTerminate() == true);

    assert(status.GetTerminationSignal() == 1);
    assert(status.GetTerminationTimestamp() != 0);

    status.End();
    assert(status.IsStart() == true);
    assert(status.IsEnd() == true);
    assert(status.IsError() == true);
    assert(status.IsTerminate() == true);

    assert(status.GetEndTimestamp() != 0);


    return 0;
}
