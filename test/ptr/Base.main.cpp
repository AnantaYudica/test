#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/ptr/Base.h"

#include <utility>
#include <cassert>

struct Obj1 : test::ptr::Base
{
    inline Obj1() :
        test::ptr::Base()
    {}
    inline ~Obj1()
    {}
    inline Obj1(const Obj1& cpy) :
        test::ptr::Base(cpy)
    {}
    inline Obj1(Obj1&& mov) :
        test::ptr::Base(std::move(mov))
    {}
    inline Obj1(test::ptr::Base&& mov) :
        test::ptr::Base(std::move(mov))
    {}
    inline Obj1& operator=(const Obj1& cpy)
    {
        test::ptr::Base::operator=(cpy);
        return *this;
    }
    inline Obj1& operator=(Obj1&& mov)
    {
        test::ptr::Base::operator=(std::move(mov));
        return *this;
    }
    using test::ptr::Base::Allocation;
    using test::ptr::Base::Deallocation;
    using test::ptr::Base::Get;
    using test::ptr::Base::GetOffset;
    using test::ptr::Base::GetCount;
    using test::ptr::Base::GetTypeSize;
    using test::ptr::Base::GetDataSize;
    using test::ptr::Base::GetFlag;
    using test::ptr::Base::GetData;
    using test::ptr::Base::SetOffset;
    using test::ptr::Base::operator==;
    using test::ptr::Base::operator!=;
    using test::ptr::Base::operator bool;
    inline Obj1& operator+=(const std::size_t& size)
    {
        Base::operator+=(size);
        return *this;
    }
    inline Obj1& operator-=(const std::size_t& size)
    {
        Base::operator-=(size);
        return *this;
    }

    inline Obj1& operator++()
    {
        Base::operator++();
        return *this;
    }
    inline Obj1 operator++(int)
    {
        Obj1 ret{*this};
        Base::operator++(1);
        return ret;
    }

    inline Obj1& operator--()
    {
        Base::operator--();
        return *this;
    }
    inline Obj1 operator--(int)
    {
        Obj1 ret{*this};
        Base::operator--(1);
        return ret;
    }

    inline Obj1 operator+(const std::size_t& size)
    {
        Obj1 ret{this->Base::operator+(size)};
        return ret;
    }
    inline Obj1 operator-(const std::size_t& size)
    {
        Obj1 ret{this->Base::operator-(size)};
        return ret;
    }
};


struct Data1
{
    int i;
    float j;
    long long k;
    int * l;
    Data1() :
        i(1),
        j(2.0f),
        k(3ll),
        l(new int(4))
    {};
    Data1(int i) :
        i(i * 1),
        j(i * 2.0f),
        k(i * 3ll),
        l(new int(i * 4))
    {};
    ~Data1() 
    {
        if (l!= nullptr) delete l;
        l = nullptr;
    };
};

struct Data2
{
    Data2() {};
    virtual ~Data2() {};
    virtual int GetValue() = 0;
};

struct Data3 : Data2
{
    int* m_val;
    Data3() : Data2(), m_val(new int(1)) {}
    Data3(int val) : Data2(), m_val(new int(val)) {}
    ~Data3() {delete m_val; m_val = nullptr;}
    int GetValue() override {return *m_val;}
};

void IntDestructor(void* data)
{
    int * cast = (int*)data;
    *cast = 0;
}

template<typename T>
void TDestructor(void* data)
{
    T * cast = (T*)data;
    cast->~T();
}

int main()
{
    {
        Obj1 obj1_1;

        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);

        auto d_obj1_1 = obj1_1.Allocation(test::ptr::Flag::empty, sizeof(int),
            1, IntDestructor);

        auto p_d_obj1_1 = new(d_obj1_1) int(5);

        assert(p_d_obj1_1 == obj1_1.GetData());
        assert((bool)obj1_1 == true);
        assert(*(obj1_1.Get<int>()) == 5);
        assert(obj1_1.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(int));
        assert(obj1_1.GetDataSize() == sizeof(int));
        assert(*((int*)obj1_1.GetData()) == 5);

        *(obj1_1.Get<int>()) += 5;

        assert(p_d_obj1_1 == obj1_1.GetData());
        assert((bool)obj1_1 == true);
        assert(*(obj1_1.Get<int>()) == 10);
        assert(obj1_1.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(int));
        assert(obj1_1.GetDataSize() == sizeof(int));
        assert(*((int*)obj1_1.GetData()) == 10);

        Obj1 obj1_2{obj1_1};

        assert((bool)obj1_2 == true);
        assert(*(obj1_2.Get<int>()) == 10);
        assert(obj1_2.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_2.GetOffset() == 0);
        assert(obj1_2.GetCount() == 2);
        assert(obj1_2.GetTypeSize() == sizeof(int));
        assert(obj1_2.GetDataSize() == sizeof(int));
        assert(*((int*)obj1_2.GetData()) == 10);

        assert((obj1_2 == obj1_1) == true);
        assert((obj1_2 != obj1_1) == false);
        
        Obj1 obj1_3{std::move(obj1_2)};

        assert((bool)obj1_3 == true);
        assert(*(obj1_3.Get<int>()) == 10);
        assert(obj1_3.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_3.GetOffset() == 0);
        assert(obj1_3.GetCount() == 2);
        assert(obj1_3.GetTypeSize() == sizeof(int));
        assert(obj1_3.GetDataSize() == sizeof(int));
        assert(*((int*)obj1_3.GetData()) == 10);
        
        assert((bool)obj1_2 == false);
        assert(obj1_2.GetOffset() == 0);
        assert(obj1_2.GetCount() == 0);

        assert((obj1_3 == obj1_1) == true);
        assert((obj1_3 != obj1_1) == false);
        assert((obj1_2 == obj1_1) == false);
        assert((obj1_2 != obj1_1) == true);
        
        Obj1 obj1_4;
        
        assert((bool)obj1_4 == false);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 0);

        obj1_4 = obj1_3;
        
        assert((bool)obj1_4 == true);
        assert(*(obj1_4.Get<int>()) == 10);
        assert(obj1_4.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 3);
        assert(obj1_4.GetTypeSize() == sizeof(int));
        assert(obj1_4.GetDataSize() == sizeof(int));
        assert(*((int*)obj1_4.GetData()) == 10);

        assert((obj1_4 == obj1_3) == true);
        assert((obj1_4 != obj1_3) == false);
        
        Obj1 obj1_5;

        assert((bool)obj1_5 == false);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 0);
        
        obj1_5 = std::move(obj1_4);
        
        assert((bool)obj1_5 == true);
        assert(*(obj1_5.Get<int>()) == 10);
        assert(obj1_5.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 3);
        assert(obj1_5.GetTypeSize() == sizeof(int));
        assert(obj1_5.GetDataSize() == sizeof(int));
        assert(*((int*)obj1_5.GetData()) == 10);

        assert((bool)obj1_4 == false);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 0);

        assert((obj1_5 == obj1_1) == true);
        assert((obj1_5 != obj1_1) == false);
        assert((obj1_4 == obj1_1) == false);
        assert((obj1_4 != obj1_1) == true);

        obj1_5.Deallocation();
        
        assert((bool)obj1_5 == false);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 0);
        
        assert(obj1_1.GetCount() == 2);

        obj1_3.Deallocation();
        
        assert((bool)obj1_3 == false);
        assert(obj1_3.GetOffset() == 0);
        assert(obj1_3.GetCount() == 0);
        
        assert(obj1_1.GetCount() == 1);

        obj1_1.Deallocation();
        
        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);
    }
    {
        Obj1 obj1_1;
        constexpr std::size_t size = 10;

        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);

        obj1_1.Allocation(test::ptr::Flag::array_allocation, 
            sizeof(int), 10, IntDestructor);

        int* p_d_obj1_1[size];
        for (std::size_t i = 0; i < size; ++i)
        {
            p_d_obj1_1[i] = new(obj1_1.Get<int>()) int(i + 1);
            obj1_1 += sizeof(int);
        }
        
        assert(*p_d_obj1_1[0] == 1);
        assert(*p_d_obj1_1[1] == 2);
        assert(*p_d_obj1_1[2] == 3);
        assert(*p_d_obj1_1[3] == 4);
        assert(*p_d_obj1_1[4] == 5);
        assert(*p_d_obj1_1[5] == 6);
        assert(*p_d_obj1_1[6] == 7);
        assert(*p_d_obj1_1[7] == 8);
        assert(*p_d_obj1_1[8] == 9);
        assert(*p_d_obj1_1[9] == 10);

        assert((bool)obj1_1 == true);
        assert(*(obj1_1.Get<int>()) == 1);
        assert(*(obj1_1.Get<int>() + 1) == 2);
        assert(*(obj1_1.Get<int>() + 2) == 3);
        assert(*(obj1_1.Get<int>() + 3) == 4);
        assert(*(obj1_1.Get<int>() + 4) == 5);
        assert(*(obj1_1.Get<int>() + 5) == 6);
        assert(*(obj1_1.Get<int>() + 6) == 7);
        assert(*(obj1_1.Get<int>() + 7) == 8);
        assert(*(obj1_1.Get<int>() + 8) == 9);
        assert(*(obj1_1.Get<int>() + 9) == 10);
        assert(obj1_1.GetFlag() == test::ptr::Flag::array_allocation);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(int));
        assert(obj1_1.GetDataSize() == (sizeof(int)*size));
        
        assert(p_d_obj1_1[0] == obj1_1.GetData());
        assert(p_d_obj1_1[1] == (((int *)obj1_1.GetData()) + 1));
        assert(p_d_obj1_1[2] == (((int *)obj1_1.GetData()) + 2));
        assert(p_d_obj1_1[3] == (((int *)obj1_1.GetData()) + 3));
        assert(p_d_obj1_1[4] == (((int *)obj1_1.GetData()) + 4));
        assert(p_d_obj1_1[5] == (((int *)obj1_1.GetData()) + 5));
        assert(p_d_obj1_1[6] == (((int *)obj1_1.GetData()) + 6));
        assert(p_d_obj1_1[7] == (((int *)obj1_1.GetData()) + 7));
        assert(p_d_obj1_1[8] == (((int *)obj1_1.GetData()) + 8));
        assert(p_d_obj1_1[9] == (((int *)obj1_1.GetData()) + 9));

        assert(obj1_1.GetOffset() == 0);

        Obj1 obj1_1_1 = obj1_1--;

        assert(obj1_1_1.GetOffset() == 0);

        assert(obj1_1.GetOffset() == 
            ((sizeof(int) * 9) + (sizeof(int) - 1)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1[9] + (sizeof(int) - 1)));

        Obj1 obj1_1_2 = --obj1_1;
        assert(obj1_1_2.GetOffset() == 
            ((sizeof(int) * 9) + (sizeof(int) - 2)));

        assert(obj1_1.GetOffset() == 
            ((sizeof(int) * 9) + (sizeof(int) - 2)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1[9] + (sizeof(int) - 2)));
            
        Obj1 obj1_1_3 = obj1_1++;
        
        assert(obj1_1_3.GetOffset() == 
            ((sizeof(int) * 9) + (sizeof(int) - 2)));

        assert(obj1_1.GetOffset() == 
            ((sizeof(int) * 9) + (sizeof(int) - 1)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1[9] + (sizeof(int) - 1)));
        
        Obj1 obj1_1_4 = ++obj1_1;
        
        assert(obj1_1_1.GetOffset() == 0);
        
        assert(obj1_1.GetOffset() == 0);

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[0]));

        obj1_1 += sizeof(int);
        
        assert(obj1_1.GetOffset() == sizeof(int));

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[1]));
        
        obj1_1 -= sizeof(int);
        
        assert(obj1_1.GetOffset() == 0);

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[0]));
        
        Obj1 obj1_1_5 = obj1_1 - sizeof(int);
        
        assert(obj1_1.GetOffset() == 0);
        
        assert(obj1_1_5.GetOffset() == (sizeof(int) * (size - 1)));

        assert(obj1_1_5.Get<char>() == ((char*)p_d_obj1_1[9]));

        Obj1 obj1_1_6 = obj1_1 + sizeof(int);

        assert(obj1_1.GetOffset() == 0);
        
        assert(obj1_1_6.GetOffset() == sizeof(int));

        assert(obj1_1_6.Get<char>() == ((char*)p_d_obj1_1[1]));

        obj1_1.SetOffset(sizeof(int)* 4);

        assert(obj1_1.GetOffset() == (sizeof(int)*4));

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[4]));

    }
    {
        Obj1 obj1_1;

        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);

        void * d_obj1_1 = obj1_1.Allocation(test::ptr::Flag::
            default_initialization, sizeof(Data1), 1, TDestructor<Data1>);

        auto p_d_obj1_1 = new(d_obj1_1) Data1();
        
        assert(p_d_obj1_1 == obj1_1.GetData());
        assert((bool)obj1_1 == true);
        assert((obj1_1.Get<Data1>())->i == 1);
        assert((obj1_1.Get<Data1>())->j == 2.0f);
        assert((obj1_1.Get<Data1>())->k == 3ll);
        assert(*((obj1_1.Get<Data1>())->l) == 4);

        assert(obj1_1.GetFlag() == test::ptr::Flag::default_initialization);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(Data1));
        assert(obj1_1.GetDataSize() == sizeof(Data1));

        assert(((Data1*)obj1_1.GetData())->i == 1);
        assert(((Data1*)obj1_1.GetData())->j == 2.0f);
        assert(((Data1*)obj1_1.GetData())->k == 3ll);
        assert((*((Data1*)obj1_1.GetData())->l) == 4);

        (obj1_1.Get<Data1>())->i *= 10;
        (obj1_1.Get<Data1>())->j *= 10.0f;
        (obj1_1.Get<Data1>())->k *= 10ll;
        (*(obj1_1.Get<Data1>())->l) *= 10;

        assert(p_d_obj1_1 == obj1_1.GetData());
        assert((bool)obj1_1 == true);
        assert((obj1_1.Get<Data1>())->i == 10);
        assert((obj1_1.Get<Data1>())->j == 20.0f);
        assert((obj1_1.Get<Data1>())->k == 30ll);
        assert(*((obj1_1.Get<Data1>())->l) == 40);
        assert(obj1_1.GetFlag() == test::ptr::Flag::default_initialization);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(Data1));
        assert(obj1_1.GetDataSize() == sizeof(Data1));
        
        assert(((Data1*)obj1_1.GetData())->i == 10);
        assert(((Data1*)obj1_1.GetData())->j == 20.0f);
        assert(((Data1*)obj1_1.GetData())->k == 30ll);
        assert(*(((Data1*)obj1_1.GetData())->l) == 40);

        Obj1 obj1_2{obj1_1};

        assert((bool)obj1_2 == true);
        assert((obj1_2.Get<Data1>())->i == 10);
        assert((obj1_2.Get<Data1>())->j == 20.0f);
        assert((obj1_2.Get<Data1>())->k == 30ll);
        assert(*((obj1_2.Get<Data1>())->l) == 40);
        assert(obj1_2.GetFlag() == test::ptr::Flag::default_initialization);
        assert(obj1_2.GetOffset() == 0);
        assert(obj1_2.GetCount() == 2);
        assert(obj1_2.GetTypeSize() == sizeof(Data1));
        assert(obj1_2.GetDataSize() == sizeof(Data1));
        assert(((Data1*)obj1_2.GetData())->i == 10);
        assert(((Data1*)obj1_2.GetData())->j == 20.0f);
        assert(((Data1*)obj1_2.GetData())->k == 30ll);
        assert(*(((Data1*)obj1_2.GetData())->l) == 40);


        assert((obj1_2 == obj1_1) == true);
        assert((obj1_2 != obj1_1) == false);
        
        Obj1 obj1_3{std::move(obj1_2)};

        assert((bool)obj1_3 == true);
        assert((obj1_3.Get<Data1>())->i == 10);
        assert((obj1_3.Get<Data1>())->j == 20.0f);
        assert((obj1_3.Get<Data1>())->k == 30ll);
        assert(*((obj1_3.Get<Data1>())->l) == 40);
        assert(obj1_3.GetFlag() == test::ptr::Flag::default_initialization);
        assert(obj1_3.GetOffset() == 0);
        assert(obj1_3.GetCount() == 2);
        assert(obj1_3.GetTypeSize() == sizeof(Data1));
        assert(obj1_3.GetDataSize() == sizeof(Data1));
        assert(((Data1*)obj1_3.GetData())->i == 10);
        assert(((Data1*)obj1_3.GetData())->j == 20.0f);
        assert(((Data1*)obj1_3.GetData())->k == 30ll);
        assert(*(((Data1*)obj1_3.GetData())->l) == 40);
        
        assert((bool)obj1_2 == false);
        assert(obj1_2.GetOffset() == 0);
        assert(obj1_2.GetCount() == 0);

        assert((obj1_3 == obj1_1) == true);
        assert((obj1_3 != obj1_1) == false);
        assert((obj1_2 == obj1_1) == false);
        assert((obj1_2 != obj1_1) == true);
        
        Obj1 obj1_4;
        
        assert((bool)obj1_4 == false);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 0);

        obj1_4 = obj1_3;
        
        assert((bool)obj1_4 == true);
        assert((obj1_4.Get<Data1>())->i == 10);
        assert((obj1_4.Get<Data1>())->j == 20.0f);
        assert((obj1_4.Get<Data1>())->k == 30ll);
        assert(*((obj1_4.Get<Data1>())->l) == 40);
        assert(obj1_4.GetFlag() == test::ptr::Flag::default_initialization);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 3);
        assert(obj1_4.GetTypeSize() == sizeof(Data1));
        assert(obj1_4.GetDataSize() == sizeof(Data1));
        assert(((Data1*)obj1_4.GetData())->i == 10);
        assert(((Data1*)obj1_4.GetData())->j == 20.0f);
        assert(((Data1*)obj1_4.GetData())->k == 30ll);
        assert(*(((Data1*)obj1_4.GetData())->l) == 40);

        assert((obj1_4 == obj1_3) == true);
        assert((obj1_4 != obj1_3) == false);
        
        Obj1 obj1_5;

        assert((bool)obj1_5 == false);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 0);
        
        obj1_5 = std::move(obj1_4);
        
        assert((bool)obj1_5 == true);
        assert((obj1_5.Get<Data1>())->i == 10);
        assert((obj1_5.Get<Data1>())->j == 20.0f);
        assert((obj1_5.Get<Data1>())->k == 30ll);
        assert(*((obj1_5.Get<Data1>())->l) == 40);
        assert(obj1_5.GetFlag() == test::ptr::Flag::default_initialization);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 3);
        assert(obj1_5.GetTypeSize() == sizeof(Data1));
        assert(obj1_5.GetDataSize() == sizeof(Data1));
        assert(((Data1*)obj1_5.GetData())->i == 10);
        assert(((Data1*)obj1_5.GetData())->j == 20.0f);
        assert(((Data1*)obj1_5.GetData())->k == 30ll);
        assert(*(((Data1*)obj1_5.GetData())->l) == 40);

        assert((bool)obj1_4 == false);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 0);

        assert((obj1_5 == obj1_1) == true);
        assert((obj1_5 != obj1_1) == false);
        assert((obj1_4 == obj1_1) == false);
        assert((obj1_4 != obj1_1) == true);

        obj1_5.Deallocation();
        
        assert((bool)obj1_5 == false);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 0);
        
        assert(obj1_1.GetCount() == 2);

        obj1_3.Deallocation();
        
        assert((bool)obj1_3 == false);
        assert(obj1_3.GetOffset() == 0);
        assert(obj1_3.GetCount() == 0);
        
        assert(obj1_1.GetCount() == 1);

        obj1_1.Deallocation();
        
        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);
    }
    {
        constexpr std::size_t size = 4;
        Obj1 obj1_1;

        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);

        obj1_1.Allocation(test::ptr::Flag::array_allocation,
            sizeof(Data1), size, TDestructor<Data1>);

        Data1* p_d_obj1_1[size];
        for (std::size_t i = 0; i < size; ++i)
        {
            p_d_obj1_1[i] = new(obj1_1.Get<Data1>()) Data1(i + 1);
            obj1_1 += sizeof(Data1);
        }
        
        assert(p_d_obj1_1[0]->i == 1);
        assert(p_d_obj1_1[0]->j == 2.0f);
        assert(p_d_obj1_1[0]->k == 3ll);
        assert(*(p_d_obj1_1[0]->l) == 4);
        
        assert(p_d_obj1_1[1]->i == 2);
        assert(p_d_obj1_1[1]->j == 4.0f);
        assert(p_d_obj1_1[1]->k == 6ll);
        assert(*(p_d_obj1_1[1]->l) == 8);

        assert(p_d_obj1_1[2]->i == 3);
        assert(p_d_obj1_1[2]->j == 6.0f);
        assert(p_d_obj1_1[2]->k == 9ll);
        assert(*(p_d_obj1_1[2]->l) == 12);
        
        assert(p_d_obj1_1[3]->i == 4);
        assert(p_d_obj1_1[3]->j == 8.0f);
        assert(p_d_obj1_1[3]->k == 12ll);
        assert(*(p_d_obj1_1[3]->l) == 16);

        assert((bool)obj1_1 == true);

        assert((obj1_1.Get<Data1>())->i == 1);
        assert((obj1_1.Get<Data1>())->j == 2.0f);
        assert((obj1_1.Get<Data1>())->k == 3ll);
        assert(*((obj1_1.Get<Data1>())->l) == 4);

        assert((obj1_1.Get<Data1>() + 1)->i == 2);
        assert((obj1_1.Get<Data1>() + 1)->j == 4.0f);
        assert((obj1_1.Get<Data1>() + 1)->k == 6ll);
        assert(*((obj1_1.Get<Data1>() + 1)->l) == 8);
        
        assert((obj1_1.Get<Data1>() + 2)->i == 3);
        assert((obj1_1.Get<Data1>() + 2)->j == 6.0f);
        assert((obj1_1.Get<Data1>() + 2)->k == 9ll);
        assert(*((obj1_1.Get<Data1>() + 2)->l) == 12);
        
        assert((obj1_1.Get<Data1>() + 3)->i == 4);
        assert((obj1_1.Get<Data1>() + 3)->j == 8.0f);
        assert((obj1_1.Get<Data1>() + 3)->k == 12ll);
        assert(*((obj1_1.Get<Data1>() + 3)->l) == 16);
        

        assert(obj1_1.GetFlag() == test::ptr::Flag::array_allocation);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(Data1));
        assert(obj1_1.GetDataSize() == (sizeof(Data1)*size));
        
        assert(p_d_obj1_1[0] == obj1_1.GetData());
        assert(p_d_obj1_1[1] == (((Data1 *)obj1_1.GetData()) + 1));
        assert(p_d_obj1_1[2] == (((Data1 *)obj1_1.GetData()) + 2));
        assert(p_d_obj1_1[3] == (((Data1 *)obj1_1.GetData()) + 3));

        assert(obj1_1.GetOffset() == 0);

        Obj1 obj1_1_1 = obj1_1--;

        assert(obj1_1_1.GetOffset() == 0);

        assert(obj1_1.GetOffset() == 
            ((sizeof(Data1) * 3) + (sizeof(Data1) - 1)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1[3] + (sizeof(Data1) - 1)));

        Obj1 obj1_1_2 = --obj1_1;
        assert(obj1_1_2.GetOffset() == 
            ((sizeof(Data1) * 3) + (sizeof(Data1) - 2)));

        assert(obj1_1.GetOffset() == 
            ((sizeof(Data1) * 3) + (sizeof(Data1) - 2)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1[3] + (sizeof(Data1) - 2)));
            
        Obj1 obj1_1_3 = obj1_1++;
        
        assert(obj1_1_3.GetOffset() == 
            ((sizeof(Data1) * 3) + (sizeof(Data1) - 2)));

        assert(obj1_1.GetOffset() == 
            ((sizeof(Data1) * 3) + (sizeof(Data1) - 1)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1[3] + (sizeof(Data1) - 1)));
        
        Obj1 obj1_1_4 = ++obj1_1;
        
        assert(obj1_1_1.GetOffset() == 0);
        
        assert(obj1_1.GetOffset() == 0);

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[0]));

        obj1_1 += sizeof(Data1);
        
        assert(obj1_1.GetOffset() == sizeof(Data1));

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[1]));
        
        obj1_1 -= sizeof(Data1);
        
        assert(obj1_1.GetOffset() == 0);

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[0]));
        
        Obj1 obj1_1_5 = obj1_1 - sizeof(Data1);
        
        assert(obj1_1.GetOffset() == 0);
        
        assert(obj1_1_5.GetOffset() == (sizeof(Data1) * (size - 1)));

        assert(obj1_1_5.Get<char>() == ((char*)p_d_obj1_1[3]));

        Obj1 obj1_1_6 = obj1_1 + sizeof(Data1);

        assert(obj1_1.GetOffset() == 0);
        
        assert(obj1_1_6.GetOffset() == sizeof(Data1));

        assert(obj1_1_6.Get<char>() == ((char*)p_d_obj1_1[1]));

        obj1_1.SetOffset(sizeof(Data1)* 5);

        assert(obj1_1.GetOffset() == (sizeof(Data1)*1));

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1[1]));
        
    }
    {
        Obj1 obj1_1;

        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);

        auto d_obj1_1 = obj1_1.Allocation(test::ptr::Flag::empty,
            sizeof(Data3), 1, TDestructor<Data3>);

        auto p_d_obj1_1 = new(d_obj1_1) Data3(5);

        assert(p_d_obj1_1 == obj1_1.GetData());
        assert((bool)obj1_1 == true);
        assert((obj1_1.Get<Data3>())->GetValue() == 5);
        assert((obj1_1.Get<Data2>())->GetValue() == 5);
        assert(obj1_1.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(Data3));
        assert(obj1_1.GetDataSize() == sizeof(Data3));
        assert(((Data3*)obj1_1.GetData())->GetValue() == 5);
        assert(((Data2*)obj1_1.GetData())->GetValue() == 5);

        *((obj1_1.Get<Data3>())->m_val) += 5;

        assert(p_d_obj1_1 == obj1_1.GetData());
        assert((bool)obj1_1 == true);
        assert((obj1_1.Get<Data3>())->GetValue() == 10);
        assert((obj1_1.Get<Data2>())->GetValue() == 10);
        assert(obj1_1.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(Data3));
        assert(obj1_1.GetDataSize() == sizeof(Data3));
        assert(((Data3*)obj1_1.GetData())->GetValue() == 10);
        assert(((Data2*)obj1_1.GetData())->GetValue() == 10);

        Obj1 obj1_2{obj1_1};

        assert((bool)obj1_2 == true);
        assert((obj1_2.Get<Data3>())->GetValue() == 10);
        assert((obj1_2.Get<Data2>())->GetValue() == 10);
        assert(obj1_2.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_2.GetOffset() == 0);
        assert(obj1_2.GetCount() == 2);
        assert(obj1_2.GetTypeSize() == sizeof(Data3));
        assert(obj1_2.GetDataSize() == sizeof(Data3));
        assert(((Data3*)obj1_2.GetData())->GetValue() == 10);
        assert(((Data2*)obj1_2.GetData())->GetValue() == 10);

        assert((obj1_2 == obj1_1) == true);
        assert((obj1_2 != obj1_1) == false);
        
        Obj1 obj1_3{std::move(obj1_2)};

        assert((bool)obj1_3 == true);
        assert((obj1_3.Get<Data3>())->GetValue() == 10);
        assert((obj1_3.Get<Data2>())->GetValue() == 10);
        assert(obj1_3.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_3.GetOffset() == 0);
        assert(obj1_3.GetCount() == 2);
        assert(obj1_3.GetTypeSize() == sizeof(Data3));
        assert(obj1_3.GetDataSize() == sizeof(Data3));
        assert(((Data3*)obj1_3.GetData())->GetValue() == 10);
        assert(((Data2*)obj1_3.GetData())->GetValue() == 10);
        
        assert((bool)obj1_2 == false);
        assert(obj1_2.GetOffset() == 0);
        assert(obj1_2.GetCount() == 0);

        assert((obj1_3 == obj1_1) == true);
        assert((obj1_3 != obj1_1) == false);
        assert((obj1_2 == obj1_1) == false);
        assert((obj1_2 != obj1_1) == true);
        
        Obj1 obj1_4;
        
        assert((bool)obj1_4 == false);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 0);

        obj1_4 = obj1_3;
        
        assert((bool)obj1_4 == true);
        assert((obj1_4.Get<Data3>())->GetValue() == 10);
        assert((obj1_4.Get<Data2>())->GetValue() == 10);
        assert(obj1_4.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 3);
        assert(obj1_4.GetTypeSize() == sizeof(Data3));
        assert(obj1_4.GetDataSize() == sizeof(Data3));
        assert(((Data3*)obj1_4.GetData())->GetValue() == 10);
        assert(((Data2*)obj1_4.GetData())->GetValue() == 10);

        assert((obj1_4 == obj1_3) == true);
        assert((obj1_4 != obj1_3) == false);
        
        Obj1 obj1_5;

        assert((bool)obj1_5 == false);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 0);
        
        obj1_5 = std::move(obj1_4);
        
        assert((bool)obj1_5 == true);
        assert((obj1_5.Get<Data3>())->GetValue() == 10);
        assert((obj1_5.Get<Data2>())->GetValue() == 10);
        assert(obj1_5.GetFlag() == test::ptr::Flag::empty);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 3);
        assert(obj1_5.GetTypeSize() == sizeof(Data3));
        assert(obj1_5.GetDataSize() == sizeof(Data3));
        assert(((Data3*)obj1_5.GetData())->GetValue() == 10);
        assert(((Data2*)obj1_5.GetData())->GetValue() == 10);

        assert((bool)obj1_4 == false);
        assert(obj1_4.GetOffset() == 0);
        assert(obj1_4.GetCount() == 0);

        assert((obj1_5 == obj1_1) == true);
        assert((obj1_5 != obj1_1) == false);
        assert((obj1_4 == obj1_1) == false);
        assert((obj1_4 != obj1_1) == true);

        obj1_5.Deallocation();
        
        assert((bool)obj1_5 == false);
        assert(obj1_5.GetOffset() == 0);
        assert(obj1_5.GetCount() == 0);
        
        assert(obj1_1.GetCount() == 2);

        obj1_3.Deallocation();
        
        assert((bool)obj1_3 == false);
        assert(obj1_3.GetOffset() == 0);
        assert(obj1_3.GetCount() == 0);
        
        assert(obj1_1.GetCount() == 1);

        obj1_1.Deallocation();
        
        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);
        
    }
    {
        Obj1 obj1_1;
        constexpr std::size_t size = 6;

        assert((bool)obj1_1 == false);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 0);

        obj1_1.Allocation(test::ptr::Flag::array_allocation, 
            sizeof(Data3), size, TDestructor<Data3>);

        Data2* p_d_obj1_1_a[size];
        Data3* p_d_obj1_1_b[size];
        for (std::size_t i = 0; i < size; ++i)
        {
            p_d_obj1_1_a[i] = new(obj1_1.Get<Data3>()) Data3(i + 1);
            p_d_obj1_1_b[i] = (Data3*) p_d_obj1_1_a[i];
            obj1_1 += sizeof(Data3);
        }
        
        assert(p_d_obj1_1_a[0]->GetValue() == 1);
        assert(p_d_obj1_1_a[1]->GetValue() == 2);
        assert(p_d_obj1_1_a[2]->GetValue() == 3);
        assert(p_d_obj1_1_a[3]->GetValue() == 4);
        assert(p_d_obj1_1_a[4]->GetValue() == 5);
        assert(p_d_obj1_1_a[5]->GetValue() == 6);

        assert(p_d_obj1_1_b[0]->GetValue() == 1);
        assert(p_d_obj1_1_b[1]->GetValue() == 2);
        assert(p_d_obj1_1_b[2]->GetValue() == 3);
        assert(p_d_obj1_1_b[3]->GetValue() == 4);
        assert(p_d_obj1_1_b[4]->GetValue() == 5);
        assert(p_d_obj1_1_b[5]->GetValue() == 6);

        assert((bool)obj1_1 == true);
        assert((obj1_1.Get<Data3>())->GetValue() == 1);
        assert((obj1_1.Get<Data3>() + 1)->GetValue() == 2);
        assert((obj1_1.Get<Data3>() + 2)->GetValue() == 3);
        assert((obj1_1.Get<Data3>() + 3)->GetValue() == 4);
        assert((obj1_1.Get<Data3>() + 4)->GetValue() == 5);
        assert((obj1_1.Get<Data3>() + 5)->GetValue() == 6);

        assert(obj1_1.GetFlag() == test::ptr::Flag::array_allocation);
        assert(obj1_1.GetOffset() == 0);
        assert(obj1_1.GetCount() == 1);
        assert(obj1_1.GetTypeSize() == sizeof(Data3));
        assert(obj1_1.GetDataSize() == (sizeof(Data3)*size));
        
        assert(p_d_obj1_1_a[0] == obj1_1.GetData());
        assert(p_d_obj1_1_a[1] == (((Data3 *)obj1_1.GetData()) + 1));
        assert(p_d_obj1_1_a[2] == (((Data3 *)obj1_1.GetData()) + 2));
        assert(p_d_obj1_1_a[3] == (((Data3 *)obj1_1.GetData()) + 3));
        assert(p_d_obj1_1_a[4] == (((Data3 *)obj1_1.GetData()) + 4));
        assert(p_d_obj1_1_a[5] == (((Data3 *)obj1_1.GetData()) + 5));

        assert(obj1_1.GetOffset() == 0);

        Obj1 obj1_1_1 = obj1_1--;

        assert(obj1_1_1.GetOffset() == 0);

        assert(obj1_1.GetOffset() == 
            ((sizeof(Data3) * 5) + (sizeof(Data3) - 1)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1_a[5] + (sizeof(Data3) - 1)));

        Obj1 obj1_1_2 = --obj1_1;
        assert(obj1_1_2.GetOffset() == 
            ((sizeof(Data3) * 5) + (sizeof(Data3) - 2)));

        assert(obj1_1.GetOffset() == 
            ((sizeof(Data3) * 5) + (sizeof(Data3) - 2)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1_a[5] + (sizeof(Data3) - 2)));
            
        Obj1 obj1_1_3 = obj1_1++;
        
        assert(obj1_1_3.GetOffset() == 
            ((sizeof(Data3) * 5) + (sizeof(Data3) - 2)));

        assert(obj1_1.GetOffset() == 
            ((sizeof(Data3) * 5) + (sizeof(Data3) - 1)));
        assert(obj1_1.Get<char>() == 
            ((char*)p_d_obj1_1_a[5] + (sizeof(Data3) - 1)));
        
        Obj1 obj1_1_4 = ++obj1_1;
        
        assert(obj1_1_1.GetOffset() == 0);
        
        assert(obj1_1.GetOffset() == 0);

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1_a[0]));

        obj1_1 += sizeof(Data3);
        
        assert(obj1_1.GetOffset() == sizeof(Data3));

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1_a[1]));
        
        obj1_1 -= sizeof(Data3);
        
        assert(obj1_1.GetOffset() == 0);

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1_a[0]));
        
        Obj1 obj1_1_5 = obj1_1 - sizeof(Data3);
        
        assert(obj1_1.GetOffset() == 0);
        
        assert(obj1_1_5.GetOffset() == (sizeof(Data3) * (size - 1)));

        assert(obj1_1_5.Get<char>() == ((char*)p_d_obj1_1_a[5]));

        Obj1 obj1_1_6 = obj1_1 + sizeof(Data3);

        assert(obj1_1.GetOffset() == 0);
        
        assert(obj1_1_6.GetOffset() == sizeof(Data3));

        assert(obj1_1_6.Get<char>() == ((char*)p_d_obj1_1_a[1]));

        obj1_1.SetOffset(sizeof(Data3)* 10);

        assert(obj1_1.GetOffset() == (sizeof(Data3)*4));

        assert(obj1_1.Get<char>() == ((char*)p_d_obj1_1_a[4]));

    }
    return TEST::GetInstance().Status().Get();
}
