#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/decltor/Parameter.h"

#include <cstring>
#include <cassert>

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
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[]>>::CStr()), "[]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[10]>>::CStr()), "[10]") == 0);
        
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[10]>,
        test::type::name::Pointer<int(*)[10]>,
        test::type::name::Array<int(*[])[10]>>::CStr()), "(*[])[10]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int)>,
        test::type::name::Pointer<int(*)(int)>,
        test::type::name::Array<int(*[10])(int)>>::CStr()), "(*[10])(int)") == 0);

    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int()>>::CStr()), "()") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int, int, ...) const>>::CStr()), 
        "(int, int, int, ...) const") == 0);

    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int)>,
        test::type::name::Pointer<int(*)(int, int)>,
        test::type::name::Function<int(*(int))(int, int)>>::CStr()), 
        "(*(int))(int, int)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[]>,
        test::type::name::Reference<int(&)[]>,
        test::type::name::Function<int(&())[]>>::CStr()), "(&())[]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[]>,
        test::type::name::Pointer<int(*)[]>,
        test::type::name::Function<int(*(int, int))[]>>::CStr()), 
        "(*(int, int))[]") == 0);
    
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Pointer<int*>>::CStr()), "*") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Pointer<int***volatile>>::CStr()), 
        "***volatile") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Pointer<int Obj1::*>>::CStr()), "Obj1::*") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Pointer<int*>,
        test::type::name::Pointer<int* Obj1::*>>::CStr()), "* Obj1::*") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Pointer<int*>,
        test::type::name::Array<int*[]>,
        test::type::name::Pointer<int*(**const)[]>>::CStr()),
        "*(**const)[]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Pointer<int*>,
        test::type::name::Array<int*[10]>,
        test::type::name::Pointer<int*(Obj1::*const)[10]>>::CStr()),
        "*(Obj1::*const)[10]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[9]>,
        test::type::name::Pointer<int(*)[9]>,
        test::type::name::Array<int(*[5])[9]>,
        test::type::name::Pointer<int(*(**const)[5])[9]>>::CStr()),
        "(*(**const)[5])[9]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[9]>,
        test::type::name::Pointer<int(*)[9]>,
        test::type::name::Array<int(*[5])[9]>,
        test::type::name::Pointer<int(*(Obj1::**const)[5])[9]>>::CStr()),
        "(*(Obj1::**const)[5])[9]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int)>,
        test::type::name::Pointer<int(*)(int, int)>,
        test::type::name::Array<int(*[5])(int, int)>,
        test::type::name::Pointer<int(*(**const)[5])(int, int)>>::CStr()),
        "(*(**const)[5])(int, int)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int, int)>,
        test::type::name::Pointer<int(*)(int, int, int)>,
        test::type::name::Array<int(*[5])(int, int, int)>,
        test::type::name::Pointer<int(*(Obj1::**const)[5])
            (int, int, int)>>::CStr()),
        "(*(Obj1::**const)[5])(int, int, int)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[9]>,
        test::type::name::Pointer<int(*)[9]>,
        test::type::name::Function<int(*(int, int, ...))[9]>,
        test::type::name::Pointer<int(*(**const)(int, int, ...))[9]>>::CStr()),
        "(*(**const)(int, int, ...))[9]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[9]>,
        test::type::name::Pointer<int(*)[9]>,
        test::type::name::Function<int(*(int, int, int, ...))[9]>,
        test::type::name::Pointer<int(*(Obj1::**const)
            (int, int, int ...))[9]>>::CStr()),
        "(*(Obj1::**const)(int, int, int, ...))[9]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int)>,
        test::type::name::Pointer<int(*)(int)>,
        test::type::name::Function<int(*(int, int, ...))(int)>,
        test::type::name::Pointer<int(*(**const)(int, int, ...))
            (int)>>::CStr()),
        "(*(**const)(int, int, ...))(int)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int, int, int)>,
        test::type::name::Pointer<int(*)(int, int, int, int)>,
        test::type::name::Function<int(*(int, int, int, ...))
            (int, int, int, int)>,
        test::type::name::Pointer<int(*(Obj1::**const)
            (int, int, int ...))(int, int, int, int)>>::CStr()),
        "(*(Obj1::**const)(int, int, int, ...))(int, int, int, int)") == 0);

    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Reference<int&>>::CStr()), "&") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Reference<int&&>>::CStr()), "&&") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Reference<int*&>>::CStr()), "*&") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[]>,
        test::type::name::Reference<int(&)[]>>::CStr()), "(&)[]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[8]>,
        test::type::name::Reference<int(**const&&)[8]>>::CStr()),
        "(**const&&)[8]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[8]>,
        test::type::name::Reference<int(Obj1::**const&&)[8]>>::CStr()),
        "(Obj1::**const&&)[8]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, ...)>,
        test::type::name::Reference<int(**const&&)(int, ...)>>::CStr()),
        "(**const&&)(int, ...)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, ...)>,
        test::type::name::Reference<int(Obj1::**const&&)
            (int, ...)>>::CStr()),
        "(Obj1::**const&&)(int, ...)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[8]>,
        test::type::name::Reference<int(&)[8]>,
        test::type::name::Function<int(&(int, int))[8]>,
        test::type::name::Reference<int(&(**const&&)
            (int, int))[8]>>::CStr()),
        "(&(**const&&)(int, int))[8]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Array<int[8]>,
        test::type::name::Reference<int(&)[8]>,
        test::type::name::Function<int(&(int, int))[8]>,
        test::type::name::Reference<int(&(Obj1::**const&)
            (int, int))[8]>>::CStr()),
        "(&(Obj1::**const&)(int, int))[8]") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int, int, ...)>,
        test::type::name::Reference<int(&)(int, int, int, ...)>,
        test::type::name::Function<int(&(int, int))(int, int, int, ...)>,
        test::type::name::Reference<int(&(**const&&)
            (int, int))(int, int, int, ...)>>::CStr()),
        "(&(**const&&)(int, int))(int, int, int, ...)") == 0);
    assert(strcmp(*(test::type::name::decltor::Parameter<
        test::type::name::Function<int(int, int, int, ...)>,
        test::type::name::Reference<int(&)(int, int, int, ...)>,
        test::type::name::Function<int(&(int, int, ...))(int, int, int, ...)>,
        test::type::name::Reference<int(&(Obj1::**const&)
            (int, int, ...))(int, int, int, ...)>>::CStr()),
        "(&(Obj1::**const&)(int, int, ...))(int, int, int, ...)") == 0);

    return TEST::GetInstance().Status().Get();
}
