#include "test/out/base/task/Buffer.h"

#include <cassert>
#include <cstdarg>

struct Obj1
{
    bool call_begin, call_end;
    Obj1()  :
        call_begin(false),
        call_end(false)
    {}
    bool _Begin()
    {
        call_begin = true;
        return true;
    }
    void _End()
    {
        call_end = true;
    }
};

template<typename TChar, typename TInterface>
std::size_t Print(test::out::base::task::Buffer<TChar, TInterface>& o,
    const char * format, ...) __ATTRIBUTE__((format(printf, 2, 3)));
    
template<typename TChar>
std::size_t Print(test::out::Interface<TChar>& o,
    const char * format, ...) __ATTRIBUTE__((format(printf, 2, 3)));

template<typename TChar, typename TInterface>
std::size_t Print(test::out::base::task::Buffer<TChar, TInterface>& o,
    const char * format, ...)
{
    va_list args;
    va_start(args, format);
    const auto ret = o.VPrint(format, args);
    va_end(args);
    return ret;
}
    
template<typename TChar>
std::size_t Print(test::out::Interface<TChar>& o,
    const char * format, ...) 
{
    va_list args;
    va_start(args, format);
    const auto ret = o.VPrint(format, args);
    va_end(args);
    return ret;
}

int main()
{
    typedef test::out::base::task::Buffer<char, Obj1> Buff1;
    {
        Buff1 buff1;
        assert(buff1.Print("%d", 2) == 0);
        assert(Print(buff1, "%d", 2) == 0);
        assert(buff1.Puts("test", 4) == 0);
        assert(buff1.Puts("test") == 0);
        assert(buff1.Puts(test::CString<char>("test")) == 0);
        assert(buff1.Puts(test::CString<const char>("test")) == 0);
        assert(buff1.IsGood() == false);
        assert(buff1.IsBad() == true);

    }

    test::out::CString<char> cstr1;
    Obj1 obj1_1;
    {
        Buff1 Buff1_1(&cstr1, &obj1_1, &Obj1::_Begin);
        assert(Buff1_1.Print("%d", 1) == 1);
        assert(Print(Buff1_1, "%d", 2) == 1);
        assert(Buff1_1.Puts("3", 1) == 1);
        Buff1 Buff1_2(std::move(Buff1_1));
        assert(Buff1_2.Puts("4") == 1);
        assert(Buff1_2.Puts(test::CString<char>("5")) == 1);
        assert(Buff1_2.Puts(test::CString<const char>("6")) == 1);
        assert(Buff1_2.IsGood() == true);
        assert(Buff1_2.IsBad() == false);
    }
    assert(strncmp(*(cstr1.Get()), "123456", 6) == 0);
    assert(obj1_1.call_begin == true);
    assert(obj1_1.call_end == false);
    
    test::out::CString<char> cstr2;
    Obj1 obj1_2;
    {
        Buff1 Buff1_1(&cstr2, &obj1_2, &Obj1::_Begin, &Obj1::_End);
        assert(Buff1_1.Print("%d", 1) == 1);
        assert(Print(Buff1_1, "%d", 2) == 1);
        assert(Buff1_1.Puts("3", 1) == 1);
        Buff1 Buff1_2(std::move(Buff1_1));
        assert(Buff1_2.Puts("4") == 1);
        assert(Buff1_2.Puts(test::CString<char>("5")) == 1);
        assert(Buff1_2.Puts(test::CString<const char>("6")) == 1);
        assert(Buff1_2.IsGood() == true);
        assert(Buff1_2.IsBad() == false);
    }
    assert(strncmp(*(cstr2.Get()), "123456", 6) == 0);
    assert(obj1_2.call_begin == true);
    assert(obj1_2.call_end == true);

    test::out::CString<char> cstr3;
    Obj1 obj1_3;
    {
        Buff1 Buff1_1(&cstr3, &obj1_3, &Obj1::_Begin, &Obj1::_End);
        auto& out_intf = static_cast<test::out::Interface<char>&>(Buff1_1);
        assert(out_intf.Print("%d", 1) == 1);
        assert(Print(out_intf, "%d", 2) == 1);
        assert(out_intf.Puts("3", 1) == 1);
        assert(out_intf.Puts("4") == 1);
        assert(out_intf.Puts(test::CString<char>("5")) == 1);
        assert(out_intf.Puts(test::CString<const char>("6")) == 1);
        assert(out_intf.IsGood() == true);
        assert(out_intf.IsBad() == false);
    }
    assert(strncmp(*(cstr3.Get()), "123456", 6) == 0);
    assert(obj1_3.call_begin == true);
    assert(obj1_3.call_end == true);

    return 0;
}