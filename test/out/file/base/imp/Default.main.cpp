#include "test/out/file/base/imp/Default.h"

#include <cassert>

class Obj1 :
    public test::out::file::base::imp::Default
{
private:
    typedef test::out::file::base::imp::Default BaseType;
public:
    bool call_print, call_puts, call_last_output;
    Obj1() :
        test::out::file::base::imp::Default(),
        call_print(false),
        call_puts(false),
        call_last_output(false)
    {}
    void Print()
    {
        auto guard = BaseType::PrintGuard();
        if (guard)
            call_print = true;
        else
            call_print = false;
    }
    void Puts()
    {
        auto guard = BaseType::PutsGuard();
        if (guard)
            call_puts = true;
        else
            call_puts = false;
    }
    void LastOutput()
    {
        auto guard = BaseType::LastOutputGuard();
        if (guard)
            call_last_output = true;
        else
            call_last_output = false;
    }
};

int main()
{
    Obj1 obj1_1;
    assert(obj1_1.call_print == false);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_last_output == false);

    obj1_1.Print();
    assert(obj1_1.call_print == true);
    assert(obj1_1.call_puts == false);
    assert(obj1_1.call_last_output == false);

    obj1_1.Puts();
    assert(obj1_1.call_print == true);
    assert(obj1_1.call_puts == true);
    assert(obj1_1.call_last_output == false);

    obj1_1.LastOutput();
    assert(obj1_1.call_print == true);
    assert(obj1_1.call_puts == true);
    assert(obj1_1.call_last_output == true);
    
    return 1;
}