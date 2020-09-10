#include "test/out/base/Delegate.h"
#include "test/out/base/Task.h"
#include "test/out/base/Interface.h"
#include "test/out/base/Status.h"
#include "test/out/base/imp/Default.h"
#include "test/CString.h"

#include <cstdint>
#include <cassert>
#include <cstdarg>

struct Out : test::out::base::imp::Default<char>
{
    typedef test::out::base::imp::Default<char> BaseType;
    typedef typename BaseType::DelegateType DelegateType;
    typedef typename BaseType::BaseType BaseInterfaceType;
    test::out::base::Task<char> task;
    test::out::CString<char> out_cstring;
    Out() : task() {}
    ~Out() {}
    bool ExecuteTask(const std::intptr_t& id)
    {
        if (task != id) return false;
        auto ret = task.Execute(out_cstring);
        return ret;
    }
    BaseInterfaceType& GetBaseInterface()
    {
        return *this;
    }
};

template<typename TDeleg>
std::size_t Print(TDeleg& deleg, const char * format, ...) 
    TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));

template<typename TDeleg>
std::size_t Print(TDeleg& deleg, const char * format, ...) 
{
    va_list args;
    va_start(args, format);
    const auto res = deleg.VPrint(format, args);
    va_end(args);
    return res;
}


int main()
{
    typedef typename Out::DelegateType Delegate;
    typedef typename Delegate::StatusType StatusType;

    {
        Delegate deleg1;
        assert(deleg1.IsGood() == false);
        assert(deleg1.IsBad() == true);
        assert(Print(deleg1, "check") == 0);
        assert(deleg1.Print("check") == 0);
        assert(deleg1.Puts("check") == 0);
        assert(deleg1.Puts("check", 5) == 0);
        assert(deleg1.Puts(test::CString<char>("check")) == 0);
        assert(deleg1.Puts(test::CString<const char>("check")) == 0);
        assert(deleg1.GetBadCode() == StatusType::task_and_base_intf_nullptr);
    }

    {
        Out out1;
        Delegate deleg1{&out1.GetBaseInterface(), nullptr};
        assert(deleg1.IsGood() == false);
        assert(deleg1.IsBad() == true);
        assert(Print(deleg1, "check") == 0);
        assert(deleg1.Print("check") == 0);
        assert(deleg1.Puts("check") == 0);
        assert(deleg1.Puts("check", 5) == 0);
        assert(deleg1.Puts(test::CString<char>("check")) == 0);
        assert(deleg1.Puts(test::CString<const char>("check")) == 0);
        assert(deleg1.GetBadCode() == StatusType::task_nullptr);
    }

    {
        Out out1;
        {
            Delegate deleg1{nullptr, &(out1.task)};
            assert(deleg1.IsGood() == false);
            assert(deleg1.IsBad() == true);
            assert(Print(deleg1, "check") == 5);
            assert(deleg1.Print("check") == 5);
            assert(deleg1.Puts("check") == 5);
            assert(deleg1.Puts("check", 5) == 5);
            assert(deleg1.Puts(test::CString<char>("check")) == 5);
            assert(deleg1.Puts(test::CString<const char>("check")) == 5);
            assert(deleg1.GetBadCode() == StatusType::base_intf_nullptr);
        }
        assert(out1.task.IsAssign() == false);
        assert(out1.task.IsRelease() == false);
        assert(out1.task.IsDone() == false);
        assert(out1.task.IsGood() == true);
    }
    {
        Out out1;
        {
            Delegate deleg1{&out1.GetBaseInterface(), &(out1.task)};
            assert(deleg1.IsGood() == true);
            assert(deleg1.IsBad() == false);
            assert(Print(deleg1, "check") == 5);
            assert(deleg1.Print("check") == 5);
            assert(deleg1.Puts("check") == 5);
            assert(deleg1.Puts("check", 5) == 5);
            assert(deleg1.Puts(test::CString<char>("check")) == 5);
            assert(deleg1.Puts(test::CString<const char>("check")) == 5);
            assert(deleg1.GetBadCode() == StatusType::good);
        }
        assert(out1.task.IsAssign() == true);
        assert(out1.task.IsRelease() == true);
        assert(out1.task.IsDone() == true);
        assert(out1.task.IsGood() == true);
        assert(strncmp(*(out1.out_cstring.Get()), 
            "checkcheckcheckcheckcheckcheck", 31) == 0);
    }
    {
        Out out1;
        Delegate deleg2{&out1.GetBaseInterface(), &(out1.task)};
        {
            Delegate deleg1(std::move(deleg2));
            assert(deleg1.IsGood() == true);
            assert(deleg1.IsBad() == false);
            assert(Print(deleg1, "check") == 5);
            assert(deleg1.Print("check") == 5);
            assert(deleg1.Puts("check") == 5);
            assert(deleg1.Puts("check", 5) == 5);
            assert(deleg1.Puts(test::CString<char>("check")) == 5);
            assert(deleg1.Puts(test::CString<const char>("check")) == 5);
            assert(deleg1.GetBadCode() == StatusType::good);
        }

        assert(deleg2.IsGood() == false);
        assert(deleg2.IsBad() == true);

        assert(out1.task.IsAssign() == true);
        assert(out1.task.IsRelease() == true);
        assert(out1.task.IsDone() == true);
        assert(out1.task.IsGood() == true);
        assert(strncmp(*(out1.out_cstring.Get()), 
            "checkcheckcheckcheckcheckcheck", 31) == 0);
    }
    {
        Out out1;
        Delegate deleg2{&out1.GetBaseInterface(), &(out1.task)};
        assert(deleg2.IsGood() == true);
        assert(deleg2.IsBad() == false);
        assert(Print(deleg2, "check") == 5);
        assert(deleg2.Print("check") == 5);
        assert(deleg2.Puts("check") == 5);
        assert(deleg2.Puts("check", 5) == 5);
        assert(deleg2.Puts(test::CString<char>("check")) == 5);
        assert(deleg2.Puts(test::CString<const char>("check")) == 5);
        {
            Delegate deleg1(std::move(deleg2));
            assert(deleg1.IsGood() == true);
            assert(deleg1.IsBad() == false);
            assert(Print(deleg1, "1") == 1);
            assert(deleg1.Print("2") == 1);
            assert(deleg1.Puts("3") == 1);
            assert(deleg1.Puts("4", 1) == 1);
            assert(deleg1.Puts(test::CString<char>("5")) == 1);
            assert(deleg1.Puts(test::CString<const char>("6")) == 1);
            assert(deleg1.GetBadCode() == StatusType::good);
        }
        
        assert(deleg2.IsGood() == false);
        assert(deleg2.IsBad() == true);

        assert(out1.task.IsAssign() == true);
        assert(out1.task.IsRelease() == true);
        assert(out1.task.IsDone() == true);
        assert(out1.task.IsGood() == true);
        assert(strncmp(*(out1.out_cstring.Get()), 
            "checkcheckcheckcheckcheckcheck123456", 37) == 0);
    }

}