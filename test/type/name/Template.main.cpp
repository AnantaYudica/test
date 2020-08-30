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
{
    int _Empty;
    int Val;
    int Func1(){return 1;};
    int Func1() const {return 1;};
    int Func1() volatile {return 1;};
    int Func1() const volatile {return 1;};
    
    int Func2() & {return 1;};
    int Func2() && {return 1;};
    int Func2() const & {return 1;};
    int Func2() volatile & {return 1;};
    int Func2() const volatile & {return 1;};
    int Func2() const && {return 1;};
    int Func2() volatile && {return 1;};
    int Func2() const volatile && {return 1;};
};

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

template<typename T, int T::* V>
struct Obj5
{};

template<typename T, int T::*const V>
struct Obj6
{};

template<typename T, int T::*volatile V>
struct Obj7
{};

template<typename T, int T::*const volatile V>
struct Obj8
{};

template<typename T, int (T::* V)()>
struct Obj9
{};

template<typename T, int (T::* V)() &>
struct Obj10
{};

template<typename T, int (T::* V)() &&>
struct Obj11
{};

template<typename T, int (T::* V)() const>
struct Obj12
{};

template<typename T, int (T::* V)() const &>
struct Obj13
{};

template<typename T, int (T::* V)() const &&>
struct Obj14
{};

template<typename T, int (T::* V)() volatile>
struct Obj15
{};

template<typename T, int (T::* V)() volatile &>
struct Obj16
{};

template<typename T, int (T::* V)() volatile &&>
struct Obj17
{};

template<typename T, int (T::* V)() const volatile>
struct Obj18
{};

template<typename T, int (T::* V)() const volatile &>
struct Obj19
{};

template<typename T, int (T::* V)() const volatile &&>
struct Obj20
{};

template<typename T, T... Values>
struct Obj21
{};

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

template<typename T, int T::* V>
inline auto test::type::name::tmpl::Parameter(Obj5<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int T::*, V>>;

template<typename T, int T::*const V>
inline auto test::type::name::tmpl::Parameter(Obj6<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int T::*const, V>>;
        
template<typename T, int T::*volatile V>
inline auto test::type::name::tmpl::Parameter(Obj7<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int T::*volatile, V>>;
        
template<typename T, int T::*const volatile V>
inline auto test::type::name::tmpl::Parameter(Obj8<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int T::*const volatile, V>>;
        
template<typename T, int (T::* V)()>
inline auto test::type::name::tmpl::Parameter(Obj9<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)(), V>>;
        
template<typename T, int (T::* V)() &>
inline auto test::type::name::tmpl::Parameter(Obj10<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() &, V>>;

template<typename T, int (T::* V)() &&>
inline auto test::type::name::tmpl::Parameter(Obj11<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() &&, V>>;
        
template<typename T, int (T::* V)() const>
inline auto test::type::name::tmpl::Parameter(Obj12<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() const, V>>;

template<typename T, int (T::* V)() const &>
inline auto test::type::name::tmpl::Parameter(Obj13<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() const &, V>>;

template<typename T, int (T::* V)() const &&>
inline auto test::type::name::tmpl::Parameter(Obj14<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() const &&, V>>;

template<typename T, int (T::* V)() volatile>
inline auto test::type::name::tmpl::Parameter(Obj15<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() volatile, V>>;

template<typename T, int (T::* V)() volatile &>
inline auto test::type::name::tmpl::Parameter(Obj16<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() volatile &, V>>;

template<typename T, int (T::* V)() volatile &&>
inline auto test::type::name::tmpl::Parameter(Obj17<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() volatile &&, V>>;

template<typename T, int (T::* V)() const volatile>
inline auto test::type::name::tmpl::Parameter(Obj18<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() const volatile, V>>;

template<typename T, int (T::* V)() const volatile &>
inline auto test::type::name::tmpl::Parameter(Obj19<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() const volatile &, V>>;

template<typename T, int (T::* V)() const volatile &&>
inline auto test::type::name::tmpl::Parameter(Obj20<T, V>*) -> 
    test::type::name::Parameter<T,
        test::type::name::Value<int (T::*)() const volatile &&, V>>;

template<typename T, T... I>
inline auto test::type::name::tmpl::Parameter(Obj21<T, I...>*) -> 
    test::type::name::Parameter<T, test::type::name::Value<T, I>...>;


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

template<int... i>
struct test::type::Name<Obj1<i...>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj1<i...>*>())) ParamType;
        typedef test::type::name::Template<Obj1<i...>, ParamType> TemplateType;
        static test::CString<TChar> _name = test::cstr::Format(
            (TemplateType::template CStr<TChar>().Size() + 5),
            "Obj1%s", *(TemplateType::template CStr<TChar>()));
        return {_name};
    }
}; 


template<>
struct test::type::name::val::Get<int>
{
    template<int V, typename TChar = char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 1) : (V < 0 ? (log10(abs(V)) + 2) : 1)) + 1, 
            "%d", V);
        return {_val};
    }
};

enum EObj1
{
    value_a,
    value_b,
    value_c
};

template<>
struct test::type::Name<EObj1>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar name[] = "EObj1";
        return {name};
    }
}; 

template<>
struct test::type::name::val::Enumeration<EObj1, EObj1::value_a>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar _val[] = "value_a";
        return {_val};
    }
};

template<>
struct test::type::name::val::Enumeration<EObj1, EObj1::value_b>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar _val[] = "value_b";
        return {_val};
    }
};

template<>
struct test::type::name::val::Enumeration<EObj1, EObj1::value_c>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar _val[] = "value_c";
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
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj5<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Val>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj5<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Val>, Param1Type> Template1Type;
            
        int Obj1<1, 2, 3>::* val = &Obj1<1, 2, 3>::Val;
        auto p1 = reinterpret_cast<uintptr_t*>(&val);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int Obj1<(int) 1, (int) 2, (int) 3>::*) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj6<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Val>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj6<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Val>, Param1Type> Template1Type;

        int Obj1<1, 2, 3>::* val = &Obj1<1, 2, 3>::Val;
        auto p1 = reinterpret_cast<uintptr_t*>(&val);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int Obj1<(int) 1, (int) 2, (int) 3>::*const) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj7<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Val>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj7<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Val>, Param1Type> Template1Type;

        int Obj1<1, 2, 3>::* val = &Obj1<1, 2, 3>::Val;
        auto p1 = reinterpret_cast<uintptr_t*>(&val);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int Obj1<(int) 1, (int) 2, (int) 3>::*volatile) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj8<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Val>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj8<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Val>, Param1Type> Template1Type;

        int Obj1<1, 2, 3>::* val = &Obj1<1, 2, 3>::Val;
        auto p1 = reinterpret_cast<uintptr_t*>(&val);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int Obj1<(int) 1, (int) 2, (int) 3>::*const volatile) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj9<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func1>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj9<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func1>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() = &Obj1<1, 2, 3>::Func1;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)()) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj10<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj10<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() & = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() &) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj11<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj11<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() && = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() &&) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj12<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func1>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj12<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func1>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() const = &Obj1<1, 2, 3>::Func1;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() const) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj13<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj13<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() const & = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() const &) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj14<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj14<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() const && = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() const &&) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj15<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func1>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj15<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func1>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() volatile = &Obj1<1, 2, 3>::Func1;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() volatile) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj16<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj16<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() volatile & = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() volatile &) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj17<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj17<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() volatile && = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() volatile &&) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj18<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func1>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj18<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func1>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() const volatile = &Obj1<1, 2, 3>::Func1;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() const volatile) %p>", 
            (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj19<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj19<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() const volatile & = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() "
            "const volatile &) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj20<Obj1<1, 2, 3>, &Obj1<1, 2, 3>::Func2>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj20<Obj1<1, 2, 3>, 
            &Obj1<1, 2, 3>::Func2>, Param1Type> Template1Type;

        int (Obj1<1, 2, 3>::*func)() const volatile && = &Obj1<1, 2, 3>::Func2;
        auto p1 = reinterpret_cast<uintptr_t*>(&func);
        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<Obj1<(int) 1, (int) 2, (int) 3>, "
            "(int (Obj1<(int) 1, (int) 2, (int) 3>::*)() "
            "const volatile &&) %p>", (void*)*p1);
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj21<EObj1, EObj1::value_a>*>())) 
            Param1Type;
        typedef test::type::name::Template<Obj21<EObj1, EObj1::value_a>, 
            Param1Type> Template1Type;

        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<EObj1, (EObj1) value_a>");
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    {
        typedef decltype(test::type::name::tmpl::Parameter(
            std::declval<Obj21<EObj1, EObj1::value_a,
                EObj1::value_c>*>())) Param1Type;
        typedef test::type::name::Template<Obj21<EObj1, EObj1::value_a,
                EObj1::value_c>, Param1Type> Template1Type;

        test::out::CString<char> cstr_out1;
        cstr_out1.Print("<EObj1, (EObj1) value_a, (EObj1) value_c>");
        assert(strncmp(*(Template1Type::CStr()),*(cstr_out1.Get()), 
            Template1Type::CStr().Size()) == 0);
    }
    return TEST::GetInstance().Status().Get();
}