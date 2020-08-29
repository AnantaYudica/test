#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Template.h"
#include "test/out/CString.h"

#include <cstdint>
#include <cmath>
#include <cassert>
#include <cstring>

int Func1()
{
    return 1;
}

template<int... i>
struct Obj1
{};

template<typename... TArgs>
struct Obj2
{};

template<typename T, int I, int (&F)()>
struct Obj3
{};

template<typename T, int I, int (*F)()>
struct Obj4
{
    Obj4() = delete;
};

template<int... I>
inline auto test::type::name::tmpl::Parameter(Obj1<I...>*) -> 
    test::type::name::Parameter<test::type::name::Value<int, I>...>;

template<typename T, int I, int (&F)()>
inline auto test::type::name::tmpl::Parameter(Obj3<T, I, F>*) -> 
    test::type::name::Parameter<T, test::type::name::Value<int, I>,
        test::type::name::Value<int (&)(), F>>;

template<typename T, int I, int (*F)()>
inline auto test::type::name::tmpl::Parameter(Obj4<T, I, F>*) -> 
    test::type::name::Parameter<T, test::type::name::Value<int, I>,
        test::type::name::Value<int (*)(), F>>;

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

template<>
struct test::type::name::val::Get<int>
{
    template<typename TChar = char>
    static test::CString<TChar> CStr(int v)
    {
        test::CString<TChar> _val = test::cstr::Format(
            (v > 0 ? (log10(v) + 1) : (v < 0 ? (log10(abs(v)) + 2) : 1)) + 1, 
            "%d", v);
        return {_val};
    }
};

int main()
{
    assert(strcmp(*(test::type::name::Template<Obj2<>>::CStr()),
        "<>") == 0);
    assert(strcmp(*(test::type::name::Template<Obj2<int>>::CStr()),
        "<int>") == 0);
    assert(strcmp(*(test::type::name::Template<Obj2<int, int>>::CStr()),
        "<int, int>") == 0);
    assert(strcmp(*(test::type::name::Template<Obj2<int, int, int>>::CStr()),
        "<int, int, int>") == 0);
    assert(strcmp(*(test::type::name::Template<Obj2<int, int, int, 
        int>>::CStr()), "<int, int, int, int>") == 0);

    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj1<>*>())) Param1Type;
        typedef test::type::name::Template<Obj1<>, 
            Param1Type> Template1Type;
        assert(strcmp(*(Template1Type::CStr()), "<>") == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj1<0, 100>*>())) Param1Type;
        typedef test::type::name::Template<Obj1<0, 100>, 
            Param1Type> Template1Type;
        assert(strcmp(*(Template1Type::CStr()),
            "<(int) 0, (int) 100>") == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj1<0, 100, -99>*>())) Param1Type;
        typedef test::type::name::Template<Obj1<0, 100, -99>, 
            Param1Type> Template1Type;
        assert(strcmp(*(Template1Type::CStr()),
            "<(int) 0, (int) 100, (int) -99>") == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj1<0, 100, -99, 9>*>())) Param1Type;
        typedef test::type::name::Template<Obj1<0, 100, -99, 9>, 
            Param1Type> Template1Type;
        assert(strcmp(*(Template1Type::CStr()),
            "<(int) 0, (int) 100, (int) -99, (int) 9>") == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj3<int, -999, Func1>*>())) Param1Type;
        typedef test::type::name::Template<Obj3<int, -999, Func1>, 
            Param1Type> Template1Type;
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<int, (int) %d, (int (&)()) %p>", -999, &Func1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj4<int, 12903, &Func1>*>())) Param1Type;
        typedef test::type::name::Template<Obj4<int, 12903, &Func1>, 
            Param1Type> Template1Type;
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<int, (int) %d, (int (*)()) %p>", 12903, &Func1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }

    return TEST::GetInstance().Status().Get();
}