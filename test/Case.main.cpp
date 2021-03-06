#include "test/Case.h"
#include <iostream>

struct TestA1 {};
struct TestA2 {};
struct TestA3 {};

struct TestA
{
    template<typename T>
    bool Result(const TestA1&, test::Variable<T>&)
    {
        std::cout << "Result TestA1" << std::endl;
        return true;
    }
    template<typename T>
    bool Result(const TestA2&, test::Variable<T>&)
    {
        std::cout << "Result TestA2" << std::endl;
        return true;
    }
    template<typename T>
    bool Result(const TestA3&, test::Variable<T>&)
    {
        std::cout << "Result TestA3" << std::endl;
        return false;
    }
    template<typename TCaseId, typename T>
    void Info(const TCaseId&, test::Variable<T>&)
    {
        std::cout << "Info of TestA" << std::endl;
    }
    template<typename TCaseId, typename T>
    void Debug(const TCaseId&, test::Variable<T>&)
    {
        std::cout << "Debug of TestA" << std::endl;
    }
    template<typename TCaseId, typename T>
    void Error(const TCaseId&, test::Variable<T>&)
    {
        std::cout << "Error of TestA" << std::endl;
    } 
};

int main()
{
    TestA ta;
    test::Variable<int> var1;
    test::Case<TestA, TestA1> c1(ta);
    c1.Run(var1);

    test::Case<TestA, 
        test::type::Parameter<TestA1, TestA2, TestA3>> c2(ta);
    c2.Run(var1);
    
    auto c3(c1);
    c3.Run(var1);
    
    auto c4(c1);
    c4 = c3;
    c4.Run(var1);
}
