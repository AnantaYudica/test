#include "test/out/base/task/base/imp/Default.h"

#include <cassert>

class Obj1 :
    public test::out::base::task::base::imp::Default<char>
{
private:
    typedef test::out::base::task::base::imp::Default<char> BaseType;
public:
    bool call_execute, call_assign, call_release, call_buffer;
    Obj1() :
        BaseType(),
        call_execute(false),
        call_assign(false),
        call_release(false),
        call_buffer(false)
    {}
    void Execute()
    {
        auto guard = BaseType::ExecuteGuard();
        if (guard)
            call_execute = true;
        else
            call_execute = false;
    }
    void Assign()
    {
        auto guard = BaseType::AssignGuard();
        if (guard)
            call_assign = true;
        else
            call_assign = false;
    }
    void Release()
    {
        auto guard = BaseType::ReleaseGuard();
        if (guard)
            call_release = true;
        else
            call_release = false;
    }
    void Buffer()
    {
        auto guard = BaseType::BufferGuard();
        if (guard)
            call_buffer = true;
        else
            call_buffer = false;
    }
};

int main()
{
    Obj1 obj1_1;
    assert(obj1_1.call_execute == false); 
    assert(obj1_1.call_assign == false);
    assert(obj1_1.call_release == false);
    assert(obj1_1.call_buffer == false);

    obj1_1.Execute();
    assert(obj1_1.call_execute == true); 
    assert(obj1_1.call_assign == false);
    assert(obj1_1.call_release == false);
    assert(obj1_1.call_buffer == false);

    obj1_1.Assign();
    assert(obj1_1.call_execute == true); 
    assert(obj1_1.call_assign == true);
    assert(obj1_1.call_release == false);
    assert(obj1_1.call_buffer == false);
    
    obj1_1.Release();
    assert(obj1_1.call_execute == true); 
    assert(obj1_1.call_assign == true);
    assert(obj1_1.call_release == true);
    assert(obj1_1.call_buffer == false);
    
    obj1_1.Buffer();
    assert(obj1_1.call_execute == true); 
    assert(obj1_1.call_assign == true);
    assert(obj1_1.call_release == true);
    assert(obj1_1.call_buffer == true);
    
    return 0;
}