#include "test/System.h"

#include <cassert>

int main(int argc, char* argv[])
{
    auto& sys = test::System::GetInstance();

    assert(sys.EntryPoint(argc, argv) == true);
    
    assert(sys.ReturnPoint() == 0);

    return 0;
}
