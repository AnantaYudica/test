#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_BLOCK_DLEVEL 0x7f
#define TEST_SYS_MEM_DUMMY_DLEVEL 0x7f

#include "test/arg/Block.h"

#include <cassert>
#include <utility>

struct Obj1
{
    char ch;
    int v1;
    long v2;
    Obj1() = delete;
    Obj1(int v) : ch('a'), v1(v), v2(-1) {}
    Obj1(const Obj1& cpy) : ch(cpy.ch) , v1(cpy.v1), v2(-1) {};
    Obj1(Obj1&& mov) : ch(mov.ch) , v1(mov.v1), v2(-1) {};
    void operator=(const Obj1& cpy)
    {
        ch = cpy.ch;
        v1 = cpy.v1;
        v2 = -1;
    }
};

int main()
{
    test::Pointer<std::uint8_t> blocks1{test::ptr::arg::Array{sizeof(int) * 2}};

    {
        test::arg::Block bck1;

        assert(bck1.GetHeader().IsGood() == false);
        assert(bck1.GetHeader().IsBad() == true);

        assert(bck1.GetOffset() == 0);
        assert(bck1.GetSize() == 0);

        bck1.SetHeader(test::arg::Header::Make<int>());

        assert(bck1.GetHeader().IsGood() == true);
        assert(bck1.GetHeader().IsBad() == false);

        bck1.SetOffset(2);
        assert(bck1.GetOffset() == 2);

        bck1.SetSize(sizeof(int));
        assert(bck1.GetSize() == sizeof(int));
        
        bck1.Set<int>(blocks1, 4);
        assert(bck1.Get<int>(blocks1) == 4);

        test::arg::Block bck2{bck1};
        assert(bck2.GetOffset() == 2);
        assert(bck2.GetSize() == sizeof(int));
        assert(bck2.Get<int>(blocks1) == 4);
        assert((bck2 == bck1) == true);
        assert((bck2 != bck1) == false);

        test::arg::Block bck3{bck1};
        assert(bck3.GetOffset() == 2);
        assert(bck3.GetSize() == sizeof(int));
        assert(bck3.Get<int>(blocks1) == 4);
        assert((bck3 == bck1) == true);
        assert((bck3 != bck1) == false);
    }
    {
        test::arg::Block bck1{test::arg::Header::Make<int>(),
            0, sizeof(int)};
        test::arg::Block bck2{test::arg::Header::Make<int>(),
            sizeof(int), sizeof(int)};
        
        bck1.Set<int>(blocks1, -1);
        bck2.Set<int>(blocks1, 6);

        assert(bck1.GetOffset() == 0);
        assert(bck1.GetSize() == sizeof(int));
        assert(bck1.Get<int>(blocks1) == -1);

        assert(bck2.GetOffset() == sizeof(int));
        assert(bck2.GetSize() == sizeof(int));
        assert(bck2.Get<int>(blocks1) == 6);
    }
    {
        constexpr std::size_t index0 = 0;
        constexpr std::size_t index1 = index0 + sizeof(char);
        constexpr std::size_t index2 = index1 + sizeof(unsigned long);
        constexpr std::size_t index3 = index2 + sizeof(int);
        constexpr std::size_t index4 = index3 + sizeof(double);
        constexpr std::size_t index5 = index4 + sizeof(const char*);
        constexpr std::size_t index6 = index5 + sizeof(Obj1);
        constexpr std::size_t index7 = index6 + sizeof(Obj1*);

        constexpr std::size_t block_size = 
            sizeof(char) +
            sizeof(unsigned long) + 
            sizeof(int) + 
            sizeof(double) + 
            sizeof(const char*) + 
            sizeof(Obj1) + 
            sizeof(Obj1*) + 
            sizeof(char);

        test::Pointer<std::uint8_t> blocks2{test::ptr::arg::Array{block_size}};

        test::arg::Block bck1{test::arg::Header::Make<char>(),
            index0, sizeof(char)};
        test::arg::Block bck2{test::arg::Header::Make<short>(),
            index1, sizeof(unsigned long)};
        test::arg::Block bck3{test::arg::Header::Make<int>(),
            index2, sizeof(int)};
        test::arg::Block bck4{test::arg::Header::Make<double>(),
            index3, sizeof(double)};
        test::arg::Block bck5{test::arg::Header::Make<const char*>(),
            index4, sizeof(const char*)};
        test::arg::Block bck6{test::arg::Header::Make<Obj1>(),
            index5, sizeof(Obj1)};
        test::arg::Block bck7{test::arg::Header::Make<Obj1*>(),
            index6, sizeof(Obj1*)};
        test::arg::Block bck8{test::arg::Header::Make<char>(),
            index7, sizeof(char)};
        
        const char str1[] = "test";
        Obj1 obj1{1};

        bck1.Set<char>(blocks2, 'a');
        bck2.Set<unsigned long>(blocks2, 255);
        bck3.Set<int>(blocks2, -1);
        bck4.Set<double>(blocks2, 3.14);
        bck5.Set<const char*>(blocks2, str1);
        bck6.Set<Obj1>(blocks2, Obj1{10});
        bck7.Set<Obj1*>(blocks2, &obj1);
        bck8.Set<char>(blocks2, 'Z');

        assert(bck1.Get<char>(blocks2) == 'a');
        assert(bck2.Get<unsigned long>(blocks2) == 255);
        assert(bck3.Get<int>(blocks2) == -1);
        assert(bck4.Get<double>(blocks2) == 3.14);
        assert(bck5.Get<const char*>(blocks2) == str1);
        assert(bck6.Get<Obj1>(blocks2).ch == 'a');
        assert(bck6.Get<Obj1>(blocks2).v1 == 10);
        assert(bck6.Get<Obj1>(blocks2).v2 == -1);
        assert(bck7.Get<Obj1*>(blocks2) == &obj1);
        assert(bck8.Get<char>(blocks2) == 'Z');
    }

    return 0;
}
