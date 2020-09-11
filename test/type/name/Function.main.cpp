#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Function.h"
#include "test/type/Name.h"

#include <cassert>
#include <cstring>

#include <cstdio>

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

int main()
{
    assert(strcmp(*(test::type::name::Function<int ()>::CStr()), 
        "()") == 0);
    assert(strcmp(*(test::type::name::Function<int (int)>::CStr()), 
        "(int)") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, int)>::CStr()), 
        "(int, int)") == 0);
    assert(strcmp(*(test::type::name::Function<int (...)>::CStr()), 
        "(...)") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, ...)>::CStr()), 
        "(int, ...)") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, int, ...)>::CStr()), 
        "(int, int, ...)") == 0);

    assert(strcmp(*(test::type::name::Function<int () &>::CStr()), 
        "() &") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) &>::CStr()), 
        "(int) &") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, int) &>::CStr()), 
        "(int, int) &") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) &>::CStr()), 
        "(...) &") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, ...) &>::CStr()), 
        "(int, ...) &") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, int, ...) &>::CStr()),
        "(int, int, ...) &") == 0);

    assert(strcmp(*(test::type::name::Function<int () &&>::CStr()), 
        "() &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) &&>::CStr()), 
        "(int) &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, int) &&>::CStr()), 
        "(int, int) &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) &&>::CStr()), 
        "(...) &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, ...) &&>::CStr()), 
        "(int, ...) &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) &&>::CStr()), "(int, int, ...) &&") == 0);

    assert(strcmp(*(test::type::name::Function<int () const>::CStr()), 
        "() const") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) const>::CStr()), 
        "(int) const") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, int) const>::CStr()),
        "(int, int) const") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) const>::CStr()), 
        "(...) const") == 0);
    assert(strcmp(*(test::type::name::Function<int (int, ...) const>::CStr()), 
        "(int, ...) const") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) const>::CStr()), "(int, int, ...) const") == 0);

    assert(strcmp(*(test::type::name::Function<int () volatile>::CStr()), 
        "() volatile") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) volatile>::CStr()), 
        "(int) volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) volatile>::CStr()), "(int, int) volatile") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) volatile>::CStr()), 
        "(...) volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) volatile>::CStr()), "(int, ...) volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) volatile>::CStr()), 
        "(int, int, ...) volatile") == 0);

    assert(strcmp(*(test::type::name::Function<
        int () const volatile>::CStr()), "() const volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int) const volatile>::CStr()), "(int) const volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) const volatile>::CStr()), 
        "(int, int) const volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (...) const volatile>::CStr()), "(...) const volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) const volatile>::CStr()), 
        "(int, ...) const volatile") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) const volatile>::CStr()), 
        "(int, int, ...) const volatile") == 0);
    
    assert(strcmp(*(test::type::name::Function<int () const &>::CStr()), 
        "() const &") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) const &>::CStr()), 
        "(int) const &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) const &>::CStr()), "(int, int) const &") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) const &>::CStr()), 
        "(...) const &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) const &>::CStr()), "(int, ...) const &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) const &>::CStr()), 
        "(int, int, ...) const &") == 0);

    assert(strcmp(*(test::type::name::Function<int () volatile &>::CStr()), 
        "() volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) volatile &>::CStr()), 
        "(int) volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) volatile &>::CStr()), "(int, int) volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) volatile &>::CStr()), 
        "(...) volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) volatile &>::CStr()), "(int, ...) volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) volatile &>::CStr()), 
        "(int, int, ...) volatile &") == 0);

    assert(strcmp(*(test::type::name::Function<
        int () const volatile &>::CStr()), "() const volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int) const volatile &>::CStr()), "(int) const volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) const volatile &>::CStr()), 
        "(int, int) const volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (...) const volatile &>::CStr()), "(...) const volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) const volatile &>::CStr()), 
        "(int, ...) const volatile &") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) const volatile &>::CStr()), 
        "(int, int, ...) const volatile &") == 0);
    
    assert(strcmp(*(test::type::name::Function<int () const &&>::CStr()), 
        "() const &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) const &&>::CStr()), 
        "(int) const &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) const &&>::CStr()), "(int, int) const &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) const &&>::CStr()), 
        "(...) const &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) const &&>::CStr()), "(int, ...) const &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) const &&>::CStr()), 
        "(int, int, ...) const &&") == 0);

    assert(strcmp(*(test::type::name::Function<int () volatile &&>::CStr()), 
        "() volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (int) volatile &&>::CStr()),
        "(int) volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) volatile &&>::CStr()), "(int, int) volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<int (...) volatile &&>::CStr()), 
        "(...) volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) volatile &&>::CStr()), "(int, ...) volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) volatile &&>::CStr()), 
        "(int, int, ...) volatile &&") == 0);

    assert(strcmp(*(test::type::name::Function<
        int () const volatile &&>::CStr()), "() const volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int) const volatile &&>::CStr()), 
        "(int) const volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int) const volatile &&>::CStr()), 
        "(int, int) const volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (...) const volatile &&>::CStr()),
        "(...) const volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, ...) const volatile &&>::CStr()), 
        "(int, ...) const volatile &&") == 0);
    assert(strcmp(*(test::type::name::Function<
        int (int, int, ...) const volatile &&>::CStr()), 
        "(int, int, ...) const volatile &&") == 0);
    
    return TEST::GetInstance().Status().Get();
}
