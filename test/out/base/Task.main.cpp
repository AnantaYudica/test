#include "test/out/base/Task.h"
#include "test/out/Interface.h"
#include "test/out/CString.h"

#include <cstdarg>
#include <cassert>
#include <cstdint>

struct Out : test::out::Interface<char>
{
    test::out::CString<char> cstr;
    Out()
    {}
    ~Out()
    {}
    SizeType VPrint(const char * format, va_list var_args) 
    {
        return cstr.VPrint(format, var_args);
    }

    SizeType Print(const char * format, ...) 
    {
        va_list args;
        va_start(args, format);
        const auto ret = cstr.VPrint(format, args);
        va_end(args);
        return ret;
    }

    SizeType Puts(const char * cstr, const SizeType& size)
    {
        return this->cstr.Puts(cstr, size);
    }

    SizeType Puts(const char * cstr)
    {
        return this->cstr.Puts(cstr);
    }

    SizeType Puts(const test::CString<char>& cstr)
    {
        return this->cstr.Puts(cstr);
    }

    SizeType Puts(const test::CString<const char>& cstr)
    {
        return this->cstr.Puts(cstr);
    }
    bool IsBad() const{return cstr.IsBad();};
    bool IsGood() const{return cstr.IsGood();};
};

int main()
{
    Out out1;
    test::out::base::Task<char> t1;
    std::intptr_t tid1 = 0;
    assert(t1.IsGood() == true);
    assert(t1.IsBad() == false);
    assert(t1.IsAssign() == false);
    assert(t1.IsRelease() == false);
    assert(t1.IsDone() == false);

    auto res = t1.Assign(1, tid1);
    assert(t1.IsGood() == true);
    assert(t1.IsBad() == false);
    assert(t1.IsAssign() == true);
    assert(t1.IsRelease() == false);
    assert(t1.IsDone() == false);

    assert(t1 == tid1);
    assert(t1 != 0);

    assert(res == true);

    {
        auto buff1 = t1.Buffer(1);
        buff1.Print("test");
    }
    res = t1.Release(1);
    assert(res == true);
    assert(t1.IsGood() == true);
    assert(t1.IsBad() == false);
    assert(t1.IsAssign() == true);
    assert(t1.IsRelease() == true);
    assert(t1.IsDone() == false);

    res = t1.Execute(out1);
    assert(res == true);
    assert(t1.IsGood() == true);
    assert(t1.IsBad() == false);
    assert(t1.IsAssign() == true);
    assert(t1.IsRelease() == true);
    assert(t1.IsDone() == true);

    test::out::base::Task<char> t2(std::move(t1));
    assert(res == true);
    assert(t2.IsGood() == true);
    assert(t2.IsBad() == false);
    assert(t2.IsAssign() == true);
    assert(t2.IsRelease() == true);
    assert(t2.IsDone() == true);

    assert(t1.IsGood() == true);
    assert(t1.IsBad() == false);
    assert(t1.IsAssign() == false);
    assert(t1.IsRelease() == false);
    assert(t1.IsDone() == false);
    
    return 0;
}