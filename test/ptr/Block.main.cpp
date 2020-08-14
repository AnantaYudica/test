#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/ptr/Block.h"

#include <cassert>
#include <utility>

#include <cstdio>

class Obj1
{
private:
    int m_val1;
    double m_val2;
public:
    Obj1() :
        m_val1(0),
        m_val2(0)
    {}
    Obj1(int val1, double val2) :
        m_val1(val1),
        m_val2(val2)
    {}
    Obj1(const Obj1& cpy) :
        m_val1(cpy.m_val1),
        m_val2(cpy.m_val2)
    {}
    Obj1(Obj1&& mov) :
        m_val1(mov.m_val1),
        m_val2(mov.m_val2)
    {
        mov.m_val1 = 0;
        mov.m_val2 = 0;
    }
    Obj1& operator=(const Obj1& cpy)
    {
        m_val1 = cpy.m_val1;
        m_val2 = cpy.m_val2;
        return *this;
    }
    Obj1& operator=(Obj1&& mov)
    {
        m_val1 = mov.m_val1;
        m_val2 = mov.m_val2;
        mov.m_val1 = 0;
        mov.m_val2 = 0;
        return *this;
    }
public:
    int GetVal1() {return m_val1;}
    double GetVal2() {return m_val2;}
    void SetVal1(int val) {m_val1 = val;}
    void SetVal2(double val) {m_val2 = val;}
};

int main()
{
    {
        test::ptr::Block bl1;
        bl1.Allocation(sizeof(int));
        
        test::ptr::FlagIntegerType& flag1 = *(bl1.GetFlag());
        int& data1 = *((int*)bl1.GetData());

        data1 = 0;
        assert(*(bl1.GetFlag()) == 
            (test::ptr::FlagIntegerType)test::ptr::Flag::empty);
        assert(*(bl1.GetSize()) == sizeof(int));
        assert(*((int*)bl1.GetData()) == 0);

        data1 = 10;
        assert(*(bl1.GetFlag()) == 
            (test::ptr::FlagIntegerType)test::ptr::Flag::empty);
        assert(*(bl1.GetSize()) == sizeof(int));
        assert(*((int*)bl1.GetData()) == 10);
        
        flag1 = (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization;
        assert(*(bl1.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl1.GetSize()) == sizeof(int));
        assert(*((int*)bl1.GetData()) == 10);

        test::ptr::Block bl2{bl1};

        assert(*(bl2.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl2.GetSize()) == sizeof(int));
        assert(*((int*)bl2.GetData()) == 10);

        test::ptr::Block bl3{std::move(bl2)};
        
        assert(*(bl3.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl3.GetSize()) == sizeof(int));
        assert(*((int*)bl3.GetData()) == 10);
        
        assert(bl2.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl2.GetSize() == test::ptr::Block{}.GetSize());
        assert(bl2.GetData() == test::ptr::Block{}.GetData());

        test::ptr::Block bl4;

        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetSize() == test::ptr::Block{}.GetSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl4 = bl3;
        
        assert(*(bl4.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl4.GetSize()) == sizeof(int));
        assert(*((int*)bl4.GetData()) == 10);
        
        test::ptr::Block bl5;

        bl5 = std::move(bl4);

        assert(*(bl5.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl5.GetSize()) == sizeof(int));
        assert(*((int*)bl5.GetData()) == 10);
        
        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetSize() == test::ptr::Block{}.GetSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());
        
        bl1.Deallocation();
    }
    {
        test::ptr::Block bl1;
        bl1.Allocation(sizeof(Obj1));

        new(bl1.GetData()) Obj1();
        
        test::ptr::FlagIntegerType& flag1 = *(bl1.GetFlag());
        Obj1& data1 = *((Obj1*)bl1.GetData());
        
        assert(*(bl1.GetFlag()) == 
            (test::ptr::FlagIntegerType)test::ptr::Flag::empty);
        assert(*(bl1.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 0);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 0.0);

        data1.SetVal1(4000);
        data1.SetVal2(3.14);

        assert(*(bl1.GetFlag()) == 
            (test::ptr::FlagIntegerType)test::ptr::Flag::empty);
        assert(*(bl1.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 3.14);

        flag1 = (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization;

        assert(*(bl1.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl1.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 3.14);

        test::ptr::Block bl2{bl1};

        assert(*(bl2.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl2.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl2.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl2.GetData())->GetVal2() == 3.14);

        test::ptr::Block bl3{std::move(bl2)};

        assert(*(bl3.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl3.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl3.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl3.GetData())->GetVal2() == 3.14);
        
        assert(bl2.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl2.GetSize() == test::ptr::Block{}.GetSize());
        assert(bl2.GetData() == test::ptr::Block{}.GetData());

        test::ptr::Block bl4;

        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetSize() == test::ptr::Block{}.GetSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl4 = bl3;

        assert(*(bl4.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl4.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl4.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl4.GetData())->GetVal2() == 3.14);
        
        test::ptr::Block bl5;

        bl5 = std::move(bl4);

        assert(*(bl5.GetFlag()) == (test::ptr::FlagIntegerType)
            test::ptr::Flag::default_initialization);
        assert(*(bl5.GetSize()) == sizeof(Obj1));
        assert(((Obj1*)bl5.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl5.GetData())->GetVal2() == 3.14);
        
        
        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetSize() == test::ptr::Block{}.GetSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());
        
        bl1.Deallocation();
    }

    return TEST::GetInstance().Status().Get();
}