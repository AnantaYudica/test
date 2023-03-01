#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/print/imp/Object.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

struct Obj1
{
    char cV;
    double dV;
    Obj1() : cV('\0'), dV(0.0) {}
    Obj1(double v) : cV('1'), dV(v) {}
    Obj1(const Obj1& cpy) : cV(cpy.cV), dV(cpy.dV) {}
};

struct Obj2
{
    char cV;
    int iV;
    Obj2() : cV('\0'), iV(0) {}
    Obj2(int v) : cV('1'), iV(v) {}
    Obj2(const Obj2& cpy) : cV(cpy.cV), iV(cpy.iV) {}
};

struct Obj3
{
    char cV;
    int iV;
    Obj3() : cV('\0'), iV(0) {}
    Obj3(int v) : cV('2'), iV(v) {}
    Obj3(const Obj2& cpy) : cV(cpy.cV), iV(cpy.iV) {}
};

template<>
struct test::out::print::imp::Object<Obj2> :
    test::out::print::imp::Object<void>
{
    
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        auto cast = (Obj2*)value;
        return out.Print("cV=%c, iV=%d", cast->cV, cast->iV);
    }
};

template<>
struct test::out::print::imp::Object<Obj3> :
    test::out::print::imp::Object<void>
{
    
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        auto cast = (Obj3*)value;
        return out.Print("cV=%c, iV=%d, type=char", cast->cV, cast->iV);
    }
    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        auto cast = (Obj3*)value;
        return out.Print(L"cV=%c, iV=%d, type=wchar", cast->cV, cast->iV);
    }
};

typedef typename test::out::Definition::FlagType FlagType;

int main()
{
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 0);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(strcmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 0);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);

        out3.Print(L"{%s}", *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(wcscmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 0, 0);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(strcmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 0, 0);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print(L"{%s}", *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(wcscmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 0, 0);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(strcmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<wchar_t> out2;
        test::out::CString<wchar_t> out3;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 0, 0);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print(L"{%ls}", *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(wcscmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    //
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::w_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 40, 0);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);
        
        out3.Print("{%s}", *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::w_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 40, 0);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);

        out3.Print(L"{%s}", *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::w_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 40, 0);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::w_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 40, 0);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print(L"{%s}", *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);

    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::w_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 40, 0);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::w_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<wchar_t> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 40, 0);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print(L"{%ls}", *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);

    }
    //
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 10);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);
        
        out3.Print("{%s}", *(out2.Get()));
        out4.Print("%.*s", 10, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 1);

        assert(out1.Size() == 1);
        assert(strcmp(*(out1.Get()), "{") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 2);

        assert(out1.Size() == 2);
        assert(strcmp(*(out1.Get()), "{}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 3);

        assert(out1.Size() == 3);
        assert(strcmp(*(out1.Get()), "{.}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 4);

        assert(out1.Size() == 4);
        assert(strcmp(*(out1.Get()), "{..}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 5);

        assert(out1.Size() == 5);
        assert(strcmp(*(out1.Get()), "{...}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 10);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);

        out3.Print(L"{%s}", *(out2.Get()));
        out4.Print(L"%.*ls", 10, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 1);

        assert(out1.Size() == 1);
        assert(wcscmp(*(out1.Get()), L"{") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 2);

        assert(out1.Size() == 2);
        assert(wcscmp(*(out1.Get()), L"{}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 3);

        assert(out1.Size() == 3);
        assert(wcscmp(*(out1.Get()), L"{.}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 4);

        assert(out1.Size() == 4);
        assert(wcscmp(*(out1.Get()), L"{..}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 0, 5);

        assert(out1.Size() == 5);
        assert(wcscmp(*(out1.Get()), L"{...}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 0, 20);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));
        out4.Print("%.*s", 20, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 0, 10);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print("{%.*s...}", 5, *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(strcmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 0, 20);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print(L"{%s}", *(out2.Get()));
        out4.Print(L"%.*ls", 20, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 0, 10);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print(L"{%.*s...}", 5, *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(wcscmp(*(out1.Get()), *(out3.Get())) == 0);
    }

    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 0, 23);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print("{%s}", *(out2.Get()));
        out4.Print("%.*s", 23, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 0, 20);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print("{%.*s...}", 15, *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(strcmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<wchar_t> out2;
        test::out::CString<wchar_t> out3;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 0, 24);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print(L"{%.*ls}", 24, *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(wcscmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::l_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<wchar_t> out2;
        test::out::CString<wchar_t> out3;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 0, 20);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print(L"{%.*ls...}", 15, *(out2.Get()));

        assert(out1.Size() == out3.Size());
        assert(wcscmp(*(out1.Get()), *(out3.Get())) == 0);
    }
    //
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 10);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);
        
        out3.Print("{%.*s}", 10, *(out2.Get()));
        out4.Print("%*s", 10, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 1);

        assert(out1.Size() == 10);
        assert(strcmp(*(out1.Get()), "         {") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 2);

        assert(out1.Size() == 10);
        assert(strcmp(*(out1.Get()), "        {}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 3);

        assert(out1.Size() == 10);
        assert(strcmp(*(out1.Get()), "       {.}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 4);

        assert(out1.Size() == 10);
        assert(strcmp(*(out1.Get()), "      {..}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 5);

        assert(out1.Size() == 10);
        assert(strcmp(*(out1.Get()), "     {...}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 10);
        test::out::print::imp::Object<Obj1>::Output(out2,
            &obj, sizeof(Obj1), FlagType{}, 0, 0);

        out3.Print(L"{%.*s}", 10, *(out2.Get()));
        out4.Print(L"%*ls", 10, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 1);

        assert(out1.Size() == 10);
        assert(wcscmp(*(out1.Get()), L"         {") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 2);

        assert(out1.Size() == 10);
        assert(wcscmp(*(out1.Get()), L"        {}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 3);

        assert(out1.Size() == 10);
        assert(wcscmp(*(out1.Get()), L"       {.}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 4);

        assert(out1.Size() == 10);
        assert(wcscmp(*(out1.Get()), L"      {..}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        Obj1 obj{3.14};
        test::out::print::imp::Object<Obj1, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj1), FlagType{}, 10, 5);

        assert(out1.Size() == 10);
        assert(wcscmp(*(out1.Get()), L"     {...}") == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 40, 20);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print("{%.*s}", 20, *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 40, 10);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print("{%.*s...}", 5, *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 40, 20);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print(L"{%.*s}", 20, *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<char> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj2 obj{4};
        test::out::print::imp::Object<Obj2, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj2), FlagType{}, 40, 10);
        test::out::print::imp::Object<Obj2>::Output(out2,
            &obj, sizeof(Obj2), FlagType{}, 0, 0);

        out3.Print(L"{%.*s...}", 5, *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }

    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 40, 23);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print("{%.*s}", 23, *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<char> out1;
        test::out::CString<char> out2;
        test::out::CString<char> out3;
        test::out::CString<char> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 40, 20);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print("{%.*s...}", 15, *(out2.Get()));
        out4.Print("%*s", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(strcmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<wchar_t> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 40, 24);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print(L"{%.*ls}", 24, *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    {
        constexpr auto fmt_flag = 
            test::out::print::Object::wl_obj_fmt;
        test::out::CString<wchar_t> out1;
        test::out::CString<wchar_t> out2;
        test::out::CString<wchar_t> out3;
        test::out::CString<wchar_t> out4;
        Obj3 obj{4};
        test::out::print::imp::Object<Obj3, fmt_flag>::Output(out1, 
            &obj, sizeof(Obj3), FlagType{}, 40, 20);
        test::out::print::imp::Object<Obj3>::Output(out2,
            &obj, sizeof(Obj3), FlagType{}, 0, 0);

        out3.Print(L"{%.*ls...}", 15, *(out2.Get()));
        out4.Print(L"%*ls", 40, *(out3.Get()));

        assert(out1.Size() == out4.Size());
        assert(wcscmp(*(out1.Get()), *(out4.Get())) == 0);
    }
    return 0;
}
