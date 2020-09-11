#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/Name.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

#include <cstdio>

struct A {};

template<typename T1, typename T2>
struct B{};

template<typename T, T(*F)()>
struct C{};

TEST_TYPE_NAME("char", char);
TEST_TYPE_NAME("int", int);
TEST_TYPE_NAME("A", A);

template<typename T1, typename T2>
TEST_TYPE_NAME_TEMPLATE("B", B<T1, T2>);

template<typename T1, T1(*F)()>
TEST_TYPE_NAME_TMPL_DEFINE((C<T1, F>),
    test::type::name::Parameter<T1, 
    test::type::name::Value<T1(*)(), F>>);
  
template<typename T1, T1(*F)()>
TEST_TYPE_NAME_TEMPLATE("C", C<T1, F>);
  
char Func1() {return 'A';}
int Func2() {return 1;}

enum EObj1 
{
    value_a,
    value_b,
    value_c
};

TEST_TYPE_NAME_VAL_ENUMERATION("value_a", EObj1, EObj1::value_a);
TEST_TYPE_NAME_VAL_ENUMERATION("value_b", EObj1, EObj1::value_b);
TEST_TYPE_NAME_VAL_ENUMERATION("value_c", EObj1, EObj1::value_c);

TEST_TYPE_NAME("EObj1", EObj1);

template<typename T,T...I>
struct D{};

template<typename T, T...I>
TEST_TYPE_NAME_TMPL_DEFINE((D<T, I...>),
    test::type::name::Parameter<T, 
    test::type::name::Value<T, I>...>);
  
template<typename T, T...I>
TEST_TYPE_NAME_TEMPLATE("D", D<T, I...>);

int main()
{
    assert(strcmp(*test::type::Name<char>::CStr(), "char") == 0);
    assert(strcmp(*test::type::Name<const char>::CStr(), "const char") == 0);
    assert(strcmp(*test::type::Name<volatile char>::CStr(), 
        "volatile char") == 0);
    assert(strcmp(*test::type::Name<const volatile char>::CStr(), 
        "const volatile char") == 0);
    assert(strcmp(*test::type::Name<int &>::CStr(), "int &") == 0);
    assert(strcmp(*test::type::Name<int &&>::CStr(), "int &&") == 0);
    assert(strcmp(*test::type::Name<const int &>::CStr(), "const int &") == 0);
    assert(strcmp(*test::type::Name<int *>::CStr(), "int *") == 0);
    assert(strcmp(*test::type::Name<int *const>::CStr(), "int *const") == 0);
    assert(strcmp(*test::type::Name<int *volatile>::CStr(), 
        "int *volatile") == 0);
    assert(strcmp(*test::type::Name<int *const volatile>::CStr(), 
        "int *const volatile") == 0);
    assert(strcmp(*test::type::Name<volatile int *>::CStr(), 
        "volatile int *") == 0);
    assert(strcmp(*test::type::Name<const volatile int *const>::CStr(), 
        "const volatile int *const") == 0);
    assert(strcmp(*test::type::Name<volatile int *volatile>::CStr(), 
        "volatile int *volatile") == 0);
    assert(strcmp(*test::type::Name<const volatile int *const volatile>::CStr(),
        "const volatile int *const volatile") == 0);
    assert(strcmp(*test::type::Name<A ****>::CStr(), "A ****") == 0);
    assert(strcmp(*test::type::Name<A *const***>::CStr(), "A *const***") == 0);
    assert(strcmp(*test::type::Name<A **const**>::CStr(), "A **const**") == 0);
    assert(strcmp(*test::type::Name<A ***const*>::CStr(), "A ***const*") == 0);
    assert(strcmp(*test::type::Name<A ****const>::CStr(), "A ****const") == 0);
    
    assert(strcmp(*test::type::Name<B<int, char>(A&&, const int &, char)>::
        CStr(), "B<int, char> (A &&, const int &, char)") == 0);
    assert(strcmp(*test::type::Name<B<int, char> (*)(A&&, const int &, char)>::
        CStr(), "B<int, char> (*)(A &&, const int &, char)") == 0);

    {
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("C<int, (int (*)()) %p> &&", &Func2);
        assert(strncmp(*test::type::Name<C<int, &Func2>&&>::CStr(),
            *(cstr_out1.Get()), test::type::Name<C<int, 
            &Func2>&&>::CStr().Size()) == 0);
    }

    assert(strcmp(*test::type::Name<EObj1>::CStr(), "EObj1") == 0);
    assert(strcmp(*test::type::Name<D<EObj1>>::CStr(), "D<EObj1>") == 0);
    assert(strcmp(*test::type::Name<D<EObj1, EObj1::value_a>>::CStr(), 
        "D<EObj1, (EObj1) value_a>") == 0);
    assert(strcmp(*test::type::Name<D<EObj1, EObj1::value_a, 
        EObj1::value_c>>::CStr(), "D<EObj1, (EObj1) value_a, "
        "(EObj1) value_c>") == 0);

    return TEST::GetInstance().Status().Get();
}

