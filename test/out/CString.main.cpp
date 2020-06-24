#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <utility>

using namespace test::out;

int main()
{
    CString<char> cstr1;
    assert(cstr1.Size() == 0);
    assert(cstr1.Capacity() == cstr1.MinimumCapacity());
    assert(std::strncmp(*(cstr1.Get()), "", 0) == 0);
    assert(cstr1.IsGood() == true);
    assert(cstr1.IsBad() == false);

    cstr1.Puts("", 0);
    assert(cstr1.Size() == 0);
    assert(cstr1.IsGood() == true);
    assert(cstr1.IsBad() == false);

    cstr1.Puts("1234", 4);
    assert(cstr1.Size() == 4);
    assert(cstr1.Capacity() == cstr1.MinimumCapacity());
    assert(std::strncmp(*(cstr1.Get()), "1234", 4) == 0);
    assert(cstr1.IsGood() == true);
    assert(cstr1.IsBad() == false);

    cstr1.Puts("56789101112");
    assert(cstr1.Size() == 15);
    assert(std::strncmp(*(cstr1.Get()), "123456789101112", 15) == 0);
    assert(cstr1.IsGood() == true);
    assert(cstr1.IsBad() == false);

    CString<char> cstr2{128};
    assert(cstr2.Size() == 0);
    assert(cstr2.Capacity() == 255);
    assert(cstr2.Capacity() == cstr2.MinimumCapacity());

    CString<char> cstr3{128, 128};
    assert(cstr3.Size() == 0);
    assert(cstr3.Capacity() == 255);
    assert(cstr3.Capacity() == cstr3.MinimumCapacity());
    assert(cstr3.Capacity() == cstr3.MaximumCapacity());

    CString<char> cstr4{3, 3};
    assert(cstr4.Size() == 0);
    assert(cstr4.Capacity() == 3);

    cstr4.Puts(test::CString<char>("12", 2));
    assert(cstr4.Size() == 2);
    assert(cstr4.Capacity() == 3);
    cstr4.Puts(test::CString<const char>("3", 1));
    assert(cstr4.Size() == 2);
    assert(cstr4.Capacity() == 3);
    assert(cstr4.IsBad() == true);
    assert(cstr4.IsGood() == false);
    assert(cstr4.GetBadCode() == cstr::Status::reallocation_overflow_capacity);

    CString<char> cstr5{cstr1};
    assert(cstr5.Size() == 15);
    assert(std::strncmp(*(cstr5.Get()), "123456789101112", 15) == 0);
    assert(cstr5.IsGood() == true);
    assert(cstr5.IsBad() == false);

    CString<char> cstr6{3};
    assert(cstr6.Size() == 0);
    cstr6 = cstr1;
    assert(cstr6.Size() == 15);
    assert(std::strncmp(*(cstr6.Get()), "123456789101112", 15) == 0);
    assert(cstr6.IsGood() == true);
    assert(cstr6.IsBad() == false);

    CString<char> cstr7;
    cstr7.Puts("abc");
    cstr7.Puts(cstr6);
    assert(cstr7.Size() == 18);
    assert(std::strncmp(*(cstr7.Get()), "abc123456789101112", 18) == 0);
    assert(cstr7.IsGood() == true);
    assert(cstr7.IsBad() == false);

    CString<char> cstr8{std::move(cstr5)};
    assert(cstr8.Size() == 15);
    assert(std::strncmp(*(cstr8.Get()), "123456789101112", 15) == 0);
    assert(cstr8.IsGood() == true);
    assert(cstr8.IsBad() == false);
    
    assert(cstr5.Size() == 0);
    assert(cstr5.IsGood() == true);
    assert(cstr5.IsBad() == false);

    CString<char> cstr9{3};
    assert(cstr9.Size() == 0);
    cstr9 = std::move(cstr6);
    assert(cstr9.Size() == 15);
    assert(std::strncmp(*(cstr9.Get()), "123456789101112", 15) == 0);
    assert(cstr9.IsGood() == true);
    assert(cstr9.IsBad() == false);

    assert(cstr6.Size() == 0);
    assert(cstr6.IsGood() == true);
    assert(cstr6.IsBad() == false);

    return 1;
}