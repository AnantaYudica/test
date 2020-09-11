#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Pointer.h"
#include "test/type/Name.h"

#include <cassert>
#include <cstring>

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
    {
        assert(strncmp(*(test::type::name::Pointer<void*>::CStr()), 
            "*", 1) == 0);
        assert(strncmp(*(test::type::name::Pointer<void*const>::CStr()), 
            "*const", 7) == 0);
        assert(strncmp(*(test::type::name::Pointer<void*volatile>::CStr()), 
            "*volatile", 10) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*const volatile>::CStr()), "*const volatile", 16) == 0);

        assert(strncmp(*(test::type::name::Pointer<void**>::CStr()), 
            "**", 2) == 0);
        assert(strncmp(*(test::type::name::Pointer<void**const>::CStr()), 
            "**const", 8) == 0);
        assert(strncmp(*(test::type::name::Pointer<void**volatile>::CStr()), 
            "**volatile", 11) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void**const volatile>::CStr()), "**const volatile", 17) == 0);

        assert(strncmp(*(test::type::name::Pointer<void*const*>::CStr()), 
            "*const*", 8) == 0);
        assert(strncmp(*(test::type::name::Pointer<void*const*const>::CStr()), 
            "*const*const", 13) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*const*volatile>::CStr()), "*const*volatile", 16) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*const*const volatile>::CStr()), 
            "*const*const volatile", 22) == 0);

        assert(strncmp(*(test::type::name::Pointer<void*volatile*>::CStr()), 
            "*volatile*", 11) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*volatile*const>::CStr()), "*volatile*const", 16) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*volatile*volatile>::CStr()), "*volatile*volatile", 19) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*volatile*const volatile>::CStr()), 
            "*volatile*const volatile", 25) == 0);
            
        assert(strncmp(*(test::type::name::Pointer<
            void*const volatile*>::CStr()), "*const volatile*", 17) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*const volatile*const>::CStr()), 
            "*const volatile*const", 22) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*const volatile*volatile>::CStr()), 
            "*const volatile*volatile", 25) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            void*const volatile*const volatile>::CStr()), 
            "*const volatile*const volatile", 31) == 0);

        assert(strncmp(*(test::type::name::Pointer<int Obj1::*>::CStr()), 
            "Obj1::*", 8) == 0);
        assert(strncmp(*(test::type::name::Pointer<int Obj1::*const>::CStr()), 
            "Obj1::*const", 13) == 0);
        assert(strncmp(*(test::type::name::Pointer<int Obj1::*volatile>::CStr()), 
            "Obj1::*volatile", 16) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const volatile>::CStr()), 
            "Obj1::*const volatile", 22) == 0);
        
        assert(strncmp(*(test::type::name::Pointer<int Obj1::**>::CStr()), 
            "Obj1::**", 9) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::**const>::CStr()), "Obj1::**const", 14) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::**volatile>::CStr()), "Obj1::**volatile", 17) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::**const volatile>::CStr()), 
            "Obj1::**const volatile", 23) == 0);

        
        assert(strncmp(*(test::type::name::Pointer<int Obj1::*const*>::CStr()),
            "Obj1::*const*", 14) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const*const>::CStr()), "Obj1::*const*const", 19) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const*volatile>::CStr()), 
            "Obj1::*const*volatile", 22) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const*const volatile>::CStr()), 
            "Obj1::*const*const volatile", 28) == 0);

        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*volatile*>::CStr()), "Obj1::*volatile*", 17) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*volatile*const>::CStr()), 
            "Obj1::*volatile*const", 22) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*volatile*volatile>::CStr()), 
            "Obj1::*volatile*volatile", 25) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*volatile*const volatile>::CStr()), 
            "Obj1::*volatile*const volatile", 31) == 0);
            
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const volatile*>::CStr()), 
            "Obj1::*const volatile*", 23) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const volatile*const>::CStr()), 
            "Obj1::*const volatile*const", 28) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const volatile*volatile>::CStr()), 
            "Obj1::*const volatile*volatile", 31) == 0);
        assert(strncmp(*(test::type::name::Pointer<
            int Obj1::*const volatile*const volatile>::CStr()), 
            "Obj1::*const volatile*const volatile", 37) == 0);
    }
    return TEST::GetInstance().Status().Get();
}
