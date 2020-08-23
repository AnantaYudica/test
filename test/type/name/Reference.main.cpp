#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Reference.h"
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
    assert(strncmp(*(test::type::name::Reference<int&>::CStr()), 
        "&", 2) == 0);
    assert(strncmp(*(test::type::name::Reference<int&&>::CStr()), 
        "&&", 3) == 0);
    
    assert(strncmp(*(test::type::name::Reference<int*&>::CStr()), 
        "*&", 3) == 0);
    assert(strncmp(*(test::type::name::Reference<int*&&>::CStr()), 
        "*&&", 4) == 0);
    assert(strncmp(*(test::type::name::Reference<int*const&>::CStr()), 
        "*const&", 8) == 0);
    assert(strncmp(*(test::type::name::Reference<int*const&&>::CStr()), 
        "*const&&", 9) == 0);
    assert(strncmp(*(test::type::name::Reference<int*volatile&>::CStr()), 
        "*volatile&", 11) == 0);
    assert(strncmp(*(test::type::name::Reference<int*volatile&&>::CStr()), 
        "*volatile&&", 12) == 0);

    assert(strncmp(*(test::type::name::Reference<int**&>::CStr()), 
        "**&", 4) == 0);
    assert(strncmp(*(test::type::name::Reference<int**&&>::CStr()), 
        "**&&", 5) == 0);
    assert(strncmp(*(test::type::name::Reference<int**const&>::CStr()), 
        "**const&", 9) == 0);
    assert(strncmp(*(test::type::name::Reference<int**const&&>::CStr()), 
        "**const&&", 10) == 0);
    assert(strncmp(*(test::type::name::Reference<int**volatile&>::CStr()), 
        "**volatile&", 12) == 0);
    assert(strncmp(*(test::type::name::Reference<int**volatile&&>::CStr()), 
        "**volatile&&", 13) == 0);
    
    assert(strncmp(*(test::type::name::Reference<int Obj1::*&>::CStr()), 
        "Obj1::*&", 9) == 0);
    assert(strncmp(*(test::type::name::Reference<int Obj1::*&&>::CStr()), 
        "Obj1::*&&", 10) == 0);
    assert(strncmp(*(test::type::name::Reference<int Obj1::*const&>::CStr()), 
        "Obj1::*const&", 14) == 0);
    assert(strncmp(*(test::type::name::Reference<int Obj1::*const&&>::CStr()), 
        "Obj1::*const&&", 15) == 0);
    assert(strncmp(*(test::type::name::Reference<int Obj1::*volatile&>::CStr()), 
        "Obj1::*volatile&", 17) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::*volatile&&>::CStr()), 
        "Obj1::*volatile&&", 18) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::*const volatile&>::CStr()), 
        "Obj1::*const volatile&", 23) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::*const volatile&&>::CStr()), 
        "Obj1::*const volatile&&", 24) == 0);
    
    assert(strncmp(*(test::type::name::Reference<int Obj1::**&>::CStr()), 
        "Obj1::**&", 9) == 0);
    assert(strncmp(*(test::type::name::Reference<int Obj1::**&&>::CStr()), 
        "Obj1::**&&", 11) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::**const&>::CStr()), "Obj1::**const&", 15) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::**const&&>::CStr()), "Obj1::**const&&", 16) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::**volatile&>::CStr()), "Obj1::**volatile&", 18) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::**volatile&&>::CStr()), "Obj1::**volatile&&", 19) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::**const volatile&>::CStr()), 
        "Obj1::**const volatile&", 24) == 0);
    assert(strncmp(*(test::type::name::Reference<
        int Obj1::**const volatile&&>::CStr()), 
        "Obj1::**const volatile&&", 25) == 0);
    
    return TEST::GetInstance().Status().Get();
}