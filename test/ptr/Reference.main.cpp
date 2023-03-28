#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_PTR_REFERENCE_DLEVEL 0x7f

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/ptr/Reference.h"
#include "test/Pointer.h"

#include <utility>
#include <cassert>

static int count_obj1 = 0;
static int count_obj2 = 0;
static int count_obj3 = 0;
static int count_obj4 = 0;

struct Obj1
{
    int v1;
    Obj1() : v1(0)
    {
        count_obj1++;
    }
    Obj1(const Obj1& cpy) : v1(cpy.v1)
    {
        count_obj1++;
    }
    Obj1(Obj1&& mov) : v1(mov.v1)
    {
        count_obj1++;
    }
    virtual ~Obj1()
    {
        --count_obj1;
    }
    virtual int Get() = 0;
};

struct Obj2 : Obj1
{
    float v2;
    Obj2() : Obj1(), v2(0)
    {
        count_obj2++;
    }
    Obj2(const Obj2& cpy) : Obj1(cpy), v2(cpy.v2)
    {
        count_obj2++;
    }
    Obj2(Obj2&& mov) : Obj1(std::move(mov)), v2(mov.v2)
    {
        count_obj2++;
    }
    virtual ~Obj2()
    {
        --count_obj2;
    }
    virtual int Get() override
    {
        return v1 * static_cast<int>(v2);
    };
};

struct Obj3
{
    int v1;
    Obj3() : v1(0)
    {
        count_obj3++;
    }
    Obj3(const Obj3& cpy) : v1(cpy.v1)
    {
        count_obj3++;
    }
    Obj3(Obj3&& mov) : v1(mov.v1)
    {
        count_obj3++;
    }
    ~Obj3()
    {
        count_obj3--;
    }
};

struct Obj4 : Obj3
{
    float v2;
    Obj4(int vi, float vf) : Obj3(), v2(0.0f)
    {
        v2 = vf;
        v1 = vi;
        count_obj4++;
    }
    Obj4() : v2(0.0f)
    {
        count_obj4++;
    }
    Obj4(const Obj4& cpy) : v2(cpy.v2)
    {
        count_obj4++;
    }
    Obj4(Obj4&& mov) : v2(mov.v2)
    {
        count_obj4++;
    }
    ~Obj4()
    {
        count_obj4--;
    }
};

int main()
{
    {
        test::ptr::Reference<char> ref1;

        assert(ref1 == nullptr);
        
        test::ptr::Reference<char> ref2(ref1);
        
        assert(ref2 == nullptr);
        
        test::ptr::Reference<char> ref3(std::move(ref2));
        
        assert(ref3 == nullptr);
        assert(ref2 == nullptr);
    }
    {
        test::Pointer<char> ptr1;
        test::ptr::Reference<char> ref1(ptr1);

        *ptr1 = 'A';

        assert(*ref1 == 'A');
        assert(ref1 != nullptr);
    }
    {
        test::Pointer<char> ptr1{test::ptr::arg::Array{sizeof(int)}};
        
        test::ptr::Reference<char> ref1(ptr1);

        int i = 0;
        for(auto it = ref1.Begin(); it != ref1.End(); ++it)
        {
            *it = (char)('a') + (i++);
        }

        if (sizeof(int) > 1)
        {
            assert(ref1[0] != ref1[1]);
        }
        if(sizeof(int) > 2)
        {
            assert(ref1[0] != ref1[2]);
            assert(ref1[1] != ref1[2]);
        }
        if (sizeof(int) > 3)
        {
            assert(ref1[0] != ref1[3]);
            assert(ref1[1] != ref1[3]);
            assert(ref1[2] != ref1[3]);
        }

    }
    {
        test::Pointer<const Obj4> ptr1{1, 10.23f};

        test::ptr::Reference<const Obj4> ref1(ptr1);

        auto ref2 = ref1.template ConstCast<Obj4>();

        ref2->v1 = 2;
        ref2->v2 = 23.10f;

        assert(ref1->v1 == 2);
        assert(ref1->v2 == 23.10f);
        
        test::Pointer<const Obj4> ptr2{test::ptr::arg::Array{4},
            test::ptr::arg::Foreach{}, 1, 10.23f};
        
        test::ptr::Reference<const Obj4> ref3(ptr2);
        
        auto ref4 = ref3.template ConstCast<Obj4>();
        
        int i = 2;
        for(auto it = ref4.Begin(); it != ref4.End(); ++it)
        {
            it->v1 *= (i);
            it->v2 *= (i++); 
        }

        assert(ref4[0].v1 == (1 * 2));
        assert(ref4[0].v2 == (10.23f * 2));
        assert(ref4[1].v1 == (1 * 3));
        assert(ref4[1].v2 == (10.23f * 3));
        assert(ref4[2].v1 == (1 * 4));
        assert(ref4[2].v2 == (10.23f * 4));
        assert(ref4[3].v1 == (1 * 5));
        assert(ref4[3].v2 == (10.23f * 5));
    }
    {
        test::Pointer<Obj2> ptr1{};
        
        test::ptr::Reference<Obj2> ref1(ptr1);
        ref1->v1 = 10;
        ref1->v2 = 22.22f;

        assert(ref1->Get() == (10 * 22));

        auto ref2 = ref1.DynamicCast<Obj1>();
        
        assert(ref2->Get() == ref1->Get());

        
        test::Pointer<Obj2> ptr2{test::ptr::arg::Array{4}};
        test::ptr::Reference<Obj2> ref3(ptr2);

        int i = 2;
        for(auto it = ref3.Begin(); it != ref3.End(); ++it)
        {
            it->v1 = (10 * i);
            it->v2 = (22.22f * i++); 
        }

        auto ref4 = ref3.DynamicCast<Obj1>();
        
        assert(ref4[0].Get() == (20 * static_cast<int>(22.22f * 2)));
        assert(ref4[1].Get() == (30 * static_cast<int>(22.22f * 3)));
        assert(ref4[2].Get() == (40 * static_cast<int>(22.22f * 4)));
        assert(ref4[3].Get() == (50 * static_cast<int>(22.22f * 5)));
    }
    {
        test::Pointer<char> ptr1{test::ptr::arg::Array{sizeof(int)}};
        
        test::ptr::Reference<char> ref1(ptr1);

        auto ref2 = ref1.ReinterpretCast<int>();

        *ref2 = 1;

        int count = 0;
        for (auto it = ref1.Begin(); it != ref1.End(); ++it)
        {
            if (*it > 0)
            {
                count++;
            }
        }
        assert(count == 1);
    }
    {
        test::Pointer<Obj4> ptr1{};
        
        test::ptr::Reference<Obj4> ref1(ptr1);
        ref1->v1 = 10;
        ref1->v2 = 1.23;

        auto ref2 = ref1.template StaticCast<Obj3>();
        assert(ref2->v1 == 10);
        
        test::Pointer<Obj4> ptr2{test::ptr::arg::Array{4}};
        test::ptr::Reference<Obj4> ref3(ptr2);
        ref3[0].v1 = 10;
        ref3[0].v2 = 1.23;
        ref3[1].v1 = 11;
        ref3[1].v2 = 2.23;
        ref3[2].v1 = 12;
        ref3[2].v2 = 3.23;
        ref3[3].v1 = 13;
        ref3[3].v2 = 3.23;

        auto ref4 = ref3.template StaticCast<Obj3>();
        
        assert(ref4[0].v1 == 10);
        assert(ref4[1].v1 == 11);
        assert(ref4[2].v1 == 12);
        assert(ref4[3].v1 == 13);

    }

    assert(count_obj1 == 0);
    assert(count_obj2 == 0);
    assert(count_obj3 == 0);
    assert(count_obj4 == 0);

    return 0;
}
