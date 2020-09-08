#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

template<>
struct test::type::Name<int>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar name[] = "int";
        return {name};
    }
}; 

struct Obj1
{};

template<>
struct test::type::Name<Obj1>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar name[] = "Obj1";
        return {name};
    }
}; 

int main()
{
    assert(strcmp(*(test::type::name::Declarator<
        int>::CStr()), "int") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1>::CStr()), "Obj1") == 0);
        
    assert(strcmp(*(test::type::name::Declarator<
        const int>::CStr()), "const int") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1>::CStr()), "const Obj1") == 0);
        
    assert(strcmp(*(test::type::name::Declarator<
        volatile int>::CStr()), "volatile int") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        volatile Obj1>::CStr()), "volatile Obj1") == 0);
        
    assert(strcmp(*(test::type::name::Declarator<
        const volatile int>::CStr()), "const volatile int") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const volatile Obj1>::CStr()), "const volatile Obj1") == 0);

    assert(strcmp(*(test::type::name::Declarator<
        const volatile int[]>::CStr()), "const volatile int []") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1[10]>::CStr()), "const Obj1 [10]") == 0);
        
    assert(strcmp(*(test::type::name::Declarator<
        volatile int(*[])[10]>::CStr()), "volatile int (*[])[10]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1(*[10])(int)>::CStr()), "const Obj1 (*[10])(int)") == 0);

    assert(strcmp(*(test::type::name::Declarator<
        int()>::CStr()), "int ()") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1(const int&, volatile int *, const volatile int *, 
            ...) const>::CStr()), 
        "Obj1 (const int &, volatile int *, const volatile int *, "
            "...) const") == 0);

    assert(strcmp(*(test::type::name::Declarator<
        int(*(int))(int, const volatile int &)>::CStr()), 
        "int (*(int))(int, const volatile int &)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1(&())[]>::CStr()), "const Obj1 (&())[]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1(*(Obj1 &&, int))[]>::CStr()), "Obj1 (*(Obj1 &&, int))[]") == 0);
    
    assert(strcmp(*(test::type::name::Declarator<
        const int*>::CStr()), "const int *") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1*const*volatile*const volatile>::CStr()), 
        "const Obj1 *const*volatile*const volatile") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int Obj1::*>::CStr()), "int Obj1::*") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int Obj1::*const>::CStr()), "int Obj1::*const") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int Obj1::*const volatile*volatile*const>::CStr()), 
        "int Obj1::*const volatile*volatile*const") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int *const Obj1::*const>::CStr()), "int *const Obj1::*const") == 0);

    assert(strcmp(*(test::type::name::Declarator<
        const int *const(**const)[]>::CStr()), 
        "const int *const(**const)[]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1*volatile(Obj1::*const)[10]>::CStr()),
        "Obj1 *volatile(Obj1::*const)[10]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int(*(**const)[5])[9][10]>::CStr()),
        "int (*(**const)[5])[9][10]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const int(*(Obj1::**const)[5])[9][1]>::CStr()),
        "const int (*(Obj1::**const)[5])[9][1]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const volatile int *(*(**const)[5])(int, 
            const volatile Obj1*)>::CStr()),
        "const volatile int *(*(**const)[5])(int, "
            "const volatile Obj1 *)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int& (*(Obj1::**const)[5])(int, volatile int *, int)>::CStr()),
        "int &(*(Obj1::**const)[5])(int, volatile int *, int)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1*(*(**const)(Obj1&, int, ...))[9][12]>::CStr()),
        "const Obj1 *(*(**const)(Obj1 &, int, ...))[9][12]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1*(*(Obj1::**const)(volatile Obj1 *, int, int ...))[9]>::CStr()),
        "Obj1 *(*(Obj1::**const)(volatile Obj1 *, int, int, ...))[9]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1&(*(**const)(Obj1&, int, ...))(Obj1 &)>::CStr()),
        "Obj1 &(*(**const)(Obj1 &, int, ...))(Obj1 &)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1 &(*(Obj1::**const)(Obj1 &, const int &, const int &, ...))
            (Obj1 &, const int &, const int &, int)>::CStr()),
        "Obj1 &(*(Obj1::**const)(Obj1 &, const int &, const int &, ...))"
            "(Obj1 &, const int &, const int &, int)") == 0);

    assert(strcmp(*(test::type::name::Declarator<
        const int&>::CStr()), "const int &") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1&&>::CStr()), "Obj1 &&") == 0);

    assert(strcmp(*(test::type::name::Declarator<
        int*&>::CStr()), "int *&") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const int*const volatile*volatile*const&>::CStr()), 
        "const int *const volatile*volatile*const&") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1*const volatile*volatile*const&&>::CStr()), 
        "Obj1 *const volatile*volatile*const&&") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const int *(&)[]>::CStr()), "const int *(&)[]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1 *(**const&&)[8]>::CStr()),
        "const Obj1 *(**const&&)[8]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        int*(Obj1::**const&&)[8]>::CStr()),
        "int *(Obj1::**const&&)[8]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1 &&(**const&&)(const Obj1 &, ...)>::CStr()),
        "Obj1 &&(**const&&)(const Obj1 &, ...)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1 &(Obj1::**const&&)(const Obj1 &, ...)>::CStr()),
        "const Obj1 &(Obj1::**const&&)(const Obj1 &, ...)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        Obj1 *(&(**const&&)(const int &, int &&))[8]>::CStr()),
        "Obj1 *(&(**const&&)(const int &, int &&))[8]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1 *(&(Obj1::**const&)(Obj1 &, const int &))[8]>::CStr()),
        "const Obj1 *(&(Obj1::**const&)(Obj1 &, const int &))[8]") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1 *&(&(**const&&)(Obj1 &, const int &))
            (Obj1 &, const int &, int, ...)>::CStr()),
        "const Obj1 *&(&(**const&&)(Obj1 &, const int &))"
            "(Obj1 &, const int &, int, ...)") == 0);
    assert(strcmp(*(test::type::name::Declarator<
        const Obj1 **const&(&(Obj1::**const&)
            (const Obj1 *, int, ...))(const Obj1 *, int, int, ...)>::CStr()),
        "const Obj1 **const&(&(Obj1::**const&)(const Obj1 *, int, ...))"
            "(const Obj1 *, int, int, ...)") == 0);

    return TEST::GetInstance().Status().Get();
}