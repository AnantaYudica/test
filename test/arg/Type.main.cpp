#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_STRUCTURE_DLEVEL 0x7f

#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/arg/Type.h"
#include "test/arg/Block.h"

typedef typename test::arg::Block::BufferType BufferType;

static int count_obj = 0;

class Obj
{
public:
    char ch;
    int i;
    long double ld;
public:
    Obj() : ch('d'), i(0), ld(3.14L) {count_obj++;}
    Obj(int v0, long double v1) : ch('v'), i(v0), ld(v1) {count_obj++;}
    Obj(const Obj& cpy) : ch(cpy.ch), i(cpy.i), ld(cpy.ld) {count_obj++;}
    Obj(Obj&& mov) : ch(mov.ch), i(mov.i), ld(mov.ld)  {count_obj++;}
    ~Obj() {count_obj--;}
    Obj& operator=(const Obj& cpy)
    {
        ch = cpy.ch;
        i = cpy.i;
        ld = cpy.ld;
        return *this;
    }  
    Obj& operator=(Obj&& mov)
    {
        ch = mov.ch;
        i = mov.i;
        ld = mov.ld;
        return *this;
    }
};

int main()
{
    {
        BufferType buff(test::ptr::arg::Array{sizeof(int)});
        assert(test::arg::Type<int>::Initialize(10) == 10);
        test::arg::Type<int>::Set(buff, 10);
        assert(test::arg::Type<int>::Get(buff) == 10);
    }
    {
        BufferType buff(test::ptr::arg::Array{sizeof(test::Pointer<char>)});
        assert(strcmp(&*(test::arg::Type<char*>::Initialize("test")), 
            "test") == 0);
        
        new (&*(buff.ReinterpretCast<test::Pointer<char>>())) 
            test::Pointer<char>(nullptr);
        test::arg::Type<char*>::Set(buff, "test1234");
        assert(strcmp(test::arg::Type<char*>::Get(buff), "test1234") == 0);
    }
    {
        char str1[] = "test1234";
        BufferType buff(test::ptr::arg::Array{sizeof(test::Pointer<char>)});
        new (&*(buff.ReinterpretCast<test::Pointer<char>>())) 
            test::Pointer<char>(nullptr);
        test::arg::Type<char*>::Set(buff, str1);
        assert(strcmp(test::arg::Type<char*>::Get(buff), str1) == 0);
    }
    {
        BufferType buff(test::ptr::arg::Array{sizeof(test::Pointer<wchar_t>)});
        assert(wcscmp(&*(test::arg::Type<wchar_t*>::Initialize(L"test")), 
            L"test") == 0);

        new (&*(buff.ReinterpretCast<test::Pointer<wchar_t>>())) 
            test::Pointer<wchar_t>(nullptr);
        test::arg::Type<wchar_t*>::Set(buff, L"test1234");
        assert(wcscmp(test::arg::Type<wchar_t*>::Get(buff), L"test1234") == 0);
    }
    {
        wchar_t str1[] = L"test1234";
        BufferType buff(test::ptr::arg::Array{sizeof(test::Pointer<wchar_t>)});
        new (&*(buff.ReinterpretCast<test::Pointer<wchar_t>>())) 
            test::Pointer<wchar_t>(nullptr);
        test::arg::Type<wchar_t*>::Set(buff, str1);
        assert(wcscmp(test::arg::Type<wchar_t*>::Get(buff), str1) == 0);
    }
    {
        BufferType buff(test::ptr::arg::Array{sizeof(Obj)});
        assert(test::arg::Type<Obj>::Initialize(Obj{}).ch == 'd');
        assert(test::arg::Type<Obj>::Initialize(Obj{}).i == 0);
        assert(test::arg::Type<Obj>::Initialize(Obj{}).ld == 3.14L);
        test::arg::Type<Obj>::Set(buff, Obj{});
        assert(test::arg::Type<Obj>::Get(buff).ch == 'd');
        assert(test::arg::Type<Obj>::Get(buff).i == 0);
        assert(test::arg::Type<Obj>::Get(buff).ld == 3.14L);
        
        assert(test::arg::Type<Obj>::Initialize(Obj{4, 6.28L}).ch == 'v');
        assert(test::arg::Type<Obj>::Initialize(Obj{4, 6.28L}).i == 4);
        assert(test::arg::Type<Obj>::Initialize(Obj{4, 6.28L}).ld == 6.28L);
        test::arg::Type<Obj>::Set(buff, Obj{4, 6.28L});
        assert(test::arg::Type<Obj>::Get(buff).ch == 'v');
        assert(test::arg::Type<Obj>::Get(buff).i == 4);
        assert(test::arg::Type<Obj>::Get(buff).ld == 6.28L);
    }

    assert(count_obj == 0);
    
    return TEST::GetInstance().Status().ReturnValue();
}
