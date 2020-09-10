#include "test/out/base/imp/Default.h"

#include <cassert>

struct Obj1 :
    test::out::base::imp::Default<char>
{
    bool call_request_task, call_execute_task;
    Obj1() :
        call_request_task(false),
        call_execute_task(false)
    {}
    ~Obj1()
    {}
    void RequestTask()
    {
        auto guard = RequestTaskGuard();
        if (guard)
        {
            call_request_task = true;
        }
        else
        {
            call_request_task = false;
        }
    }
    bool ExecuteTask(const std::intptr_t&)
    {
        auto guard = RequestTaskGuard();
        if (guard)
        {
            call_execute_task = true;
        }
        else
        {
            call_execute_task = false;
        }
        return true;
    }
    test::out::base::Interface<
        test::out::base::Status<std::uint8_t>>& Cast()
    {
        return *this;
    }
};

int main()
{
    Obj1 obj1_1;
    assert(obj1_1.call_request_task == false); 
    assert(obj1_1.call_execute_task == false);

    obj1_1.RequestTask();
    assert(obj1_1.call_request_task == true); 
    assert(obj1_1.call_execute_task == false);

    obj1_1.ExecuteTask(1);
    assert(obj1_1.call_request_task == true); 
    assert(obj1_1.call_execute_task == true);

    auto res = obj1_1.Cast().Finalize(1);
    assert(res == true);

    return 0;
}
