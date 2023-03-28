#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_PTR_ITERATOR_DLEVEL 0x7f

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/ptr/Iterator.h"
#include "test/Pointer.h"

#include <utility>
#include <cassert>

int main()
{
    {
        test::Pointer<char> ptr{test::ptr::arg::Array{10}};
        test::ptr::Iterator<test::Pointer, char> bg{ptr, 0 , 10, 0};
        test::ptr::Iterator<test::Pointer, char> ed{ptr, 0 , 10, 10};
        char ch = 'a';
        for(auto it = bg ; it != ed; ++it, ++ch)
        {
            *it = ch;
        }

        assert(*bg == 'a');
        assert(*(bg + 1) == 'b');
        assert(*(bg + 2) == 'c');
        assert(*(bg + 3) == 'd');
        assert(*(bg + 4) == 'e');
        assert(*(bg + 5) == 'f');
        assert(*(bg + 6) == 'g');
        assert(*(bg + 7) == 'h');
        assert(*(bg + 8) == 'i');
        assert(*(bg + 9) == 'j');
    }

    return 0;
}
