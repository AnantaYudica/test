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
    int * m_ptr;
public:
    Obj1() :
        m_val1(0),
        m_val2(0),
        m_ptr(new int(1000))
    {}
    Obj1(int val1, double val2) :
        m_val1(val1),
        m_val2(val2),
        m_ptr(new int(2000))
    {}
    ~Obj1()
    {
        delete m_ptr;
    }
    Obj1(const Obj1& cpy) :
        m_val1(cpy.m_val1),
        m_val2(cpy.m_val2),
        m_ptr(new int(3000))
    {}
    Obj1(Obj1&& mov) :
        m_val1(mov.m_val1),
        m_val2(mov.m_val2),
        m_ptr(new int(4000))
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

void IntDestructor(void* data)
{
    int * cast = (int*)data;
    *cast = 0;
}

void Obj1Destructor(void* data)
{
    Obj1 * cast = (Obj1*)data;
    cast->~Obj1();
}

int main()
{
    typedef test::ptr::Flag FlagType;
    {
        test::ptr::Block bl1;
        bl1.Allocation(FlagType::default_initialization, sizeof(int), 
            1, IntDestructor);
        
        int& data1 = *((int*)bl1.GetData());

        data1 = 0;
        assert(bl1.GetFlag() == FlagType::default_initialization);
        assert(bl1.GetTypeSize() == sizeof(int));
        assert(bl1.GetDataSize() == sizeof(int));
        assert(*((int*)bl1.GetData()) == 0);

        data1 = 10;
        assert(bl1.GetFlag() == FlagType::default_initialization);
        assert(bl1.GetTypeSize() == sizeof(int));
        assert(bl1.GetDataSize() == sizeof(int));
        assert(*((int*)bl1.GetData()) == 10);
        
        test::ptr::Block bl2{bl1};

        assert(bl2.GetFlag() == FlagType::default_initialization);
        assert(bl2.GetTypeSize() == sizeof(int));
        assert(bl2.GetDataSize() == sizeof(int));
        assert(*((int*)bl2.GetData()) == 10);

        test::ptr::Block bl3{std::move(bl2)};
        
        assert(bl3.GetFlag() == FlagType::default_initialization);
        assert(bl3.GetTypeSize() == sizeof(int));
        assert(bl3.GetDataSize() == sizeof(int));
        assert(*((int*)bl3.GetData()) == 10);

        assert(bl2.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl2.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl2.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl2.GetData() == test::ptr::Block{}.GetData());

        test::ptr::Block bl4;

        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl4.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl4 = bl3;
        
        assert(bl4.GetFlag() == FlagType::default_initialization);
        assert(bl4.GetTypeSize() == sizeof(int));
        assert(bl4.GetDataSize() == sizeof(int));
        assert(*((int*)bl4.GetData()) == 10);

        test::ptr::Block bl5;

        bl5 = std::move(bl4);

        assert(bl5.GetFlag() == FlagType::default_initialization);
        assert(bl5.GetTypeSize() == sizeof(int));
        assert(bl5.GetDataSize() == sizeof(int));
        assert(*((int*)bl5.GetData()) == 10);

        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl4.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl1.Deallocation();
    }
    {
        test::ptr::Block bl1;
        bl1.Allocation(FlagType::default_initialization, sizeof(Obj1), 
            1, Obj1Destructor);

        new(bl1.GetData()) Obj1();
        
        Obj1& data1 = *((Obj1*)bl1.GetData());
        
        assert(bl1.GetFlag() == FlagType::default_initialization);
        assert(bl1.GetTypeSize() == sizeof(Obj1));
        assert(bl1.GetDataSize() == sizeof(Obj1));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 0);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 0.0);

        data1.SetVal1(4000);
        data1.SetVal2(3.14);

        assert(bl1.GetFlag() == FlagType::default_initialization);
        assert(bl1.GetTypeSize() == sizeof(Obj1));
        assert(bl1.GetDataSize() == sizeof(Obj1));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 3.14);

        test::ptr::Block bl2{bl1};

        assert(bl2.GetFlag() == FlagType::default_initialization);
        assert(bl2.GetTypeSize() == sizeof(Obj1));
        assert(bl2.GetDataSize() == sizeof(Obj1));
        assert(((Obj1*)bl2.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl2.GetData())->GetVal2() == 3.14);

        test::ptr::Block bl3{std::move(bl2)};

        assert(bl3.GetFlag() == FlagType::default_initialization);
        assert(bl3.GetTypeSize() == sizeof(Obj1));
        assert(bl3.GetDataSize() == sizeof(Obj1));
        assert(((Obj1*)bl3.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl3.GetData())->GetVal2() == 3.14);
        
        assert(bl2.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl2.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl2.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl2.GetData() == test::ptr::Block{}.GetData());

        test::ptr::Block bl4;

        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl4.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl4 = bl3;

        assert(bl4.GetFlag() == FlagType::default_initialization);
        assert(bl4.GetTypeSize() == sizeof(Obj1));
        assert(bl4.GetDataSize() == sizeof(Obj1));
        assert(((Obj1*)bl4.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl4.GetData())->GetVal2() == 3.14);
        
        test::ptr::Block bl5;

        bl5 = std::move(bl4);

        assert(bl5.GetFlag() == FlagType::default_initialization);
        assert(bl5.GetTypeSize() == sizeof(Obj1));
        assert(bl5.GetDataSize() == sizeof(Obj1));
        assert(((Obj1*)bl5.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl5.GetData())->GetVal2() == 3.14);
        
        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl4.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl1.Deallocation();
    }
    {
        const int size = 10;
        test::ptr::Block bl1;
        void * alloc = bl1.Allocation(FlagType::default_initialization, 
            sizeof(Obj1), size, Obj1Destructor);

        for (int i = 0; i < size; ++i)
        {
            new(alloc) Obj1();
            alloc = (void*)((char*)alloc + sizeof(Obj1));
        }
        
        Obj1& data1 = *((Obj1*)bl1.GetData());
        
        assert(bl1.GetFlag() == FlagType::default_initialization);
        assert(bl1.GetTypeSize() == sizeof(Obj1));
        assert(bl1.GetDataSize() == (sizeof(Obj1) * size));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 0);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 0.0);

        data1.SetVal1(4000);
        data1.SetVal2(3.14);

        assert(bl1.GetFlag() == FlagType::default_initialization);
        assert(bl1.GetTypeSize() == sizeof(Obj1));
        assert(bl1.GetDataSize() == (sizeof(Obj1) * size));
        assert(((Obj1*)bl1.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl1.GetData())->GetVal2() == 3.14);

        test::ptr::Block bl2{bl1};

        assert(bl2.GetFlag() == FlagType::default_initialization);
        assert(bl2.GetTypeSize() == sizeof(Obj1));
        assert(bl2.GetDataSize() == (sizeof(Obj1) * size));
        assert(((Obj1*)bl2.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl2.GetData())->GetVal2() == 3.14);

        test::ptr::Block bl3{std::move(bl2)};

        assert(bl3.GetFlag() == FlagType::default_initialization);
        assert(bl3.GetTypeSize() == sizeof(Obj1));
        assert(bl3.GetDataSize() == (sizeof(Obj1) * size));
        assert(((Obj1*)bl3.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl3.GetData())->GetVal2() == 3.14);
        
        assert(bl2.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl2.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl2.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl2.GetData() == test::ptr::Block{}.GetData());

        test::ptr::Block bl4;

        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl4.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl4 = bl3;

        assert(bl4.GetFlag() == FlagType::default_initialization);
        assert(bl4.GetTypeSize() == sizeof(Obj1));
        assert(bl4.GetDataSize() == (sizeof(Obj1) * size));
        assert(((Obj1*)bl4.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl4.GetData())->GetVal2() == 3.14);
        
        test::ptr::Block bl5;

        bl5 = std::move(bl4);

        assert(bl5.GetFlag() == FlagType::default_initialization);
        assert(bl5.GetTypeSize() == sizeof(Obj1));
        assert(bl5.GetDataSize() == (sizeof(Obj1) * size));
        assert(((Obj1*)bl5.GetData())->GetVal1() == 4000);
        assert(((Obj1*)bl5.GetData())->GetVal2() == 3.14);
        
        assert(bl4.GetFlag() == test::ptr::Block{}.GetFlag());
        assert(bl4.GetTypeSize() == test::ptr::Block{}.GetTypeSize());
        assert(bl4.GetDataSize() == test::ptr::Block{}.GetDataSize());
        assert(bl4.GetData() == test::ptr::Block{}.GetData());

        bl1.Deallocation();
    }
    return TEST::GetInstance().Status().Get();
}