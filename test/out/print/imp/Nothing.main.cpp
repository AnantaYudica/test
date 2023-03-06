#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Nothing.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

typedef typename test::out::Definition::FlagType FlagType;

int main()
{
    {
        test::out::CString<char> out1;
        int v1 = 1;
        auto sz1 = test::out::print::imp::Nothing::Output(out1, 
            &v1, sizeof(int), FlagType{}, 0, 0);

        assert(sz1 == 0);
        assert(strcmp(*(out1.Get()), "") == 0);
    }
    {
        test::out::CString<wchar_t> out1;
        int v1 = 1;
        auto sz1 = test::out::print::imp::Nothing::Output(out1, 
            &v1, sizeof(int), FlagType{}, 0, 0);

        assert(sz1 == 0);
        assert(wcscmp(*(out1.Get()), L"") == 0);
    }
    return 0;
}
