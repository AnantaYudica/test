
#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/def/type/Name.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <climits>


struct Obj1
{};

TEST_TYPE_NAME("Obj1", Obj1);

template<typename T, T V>
struct Obj2
{};

template<typename T, T V>
TEST_TYPE_NAME_TMPL_DEFINE((Obj2<T, V>),
    test::type::name::Parameter<T,
        test::type::name::Value<T, V>>);

template<typename T, T V>
TEST_TYPE_NAME_TEMPLATE("Obj2", Obj2<T, V>);

int main()
{
    test::out::CString<char> out_cstr1_a, out_cstr1_b;

    //void
    auto res_a = out_cstr1_a.Print("%s", "void");
    auto res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<void>::CStr()));
    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);
    
    //boolean
    res_a = out_cstr1_a.Print("%s", "bool");
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<bool>::CStr()));
    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //nullptr_t
    res_a = out_cstr1_a.Print("%s", "std::nullptr_t");
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<std::nullptr_t>::CStr()));
    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);
    
    //character
    res_a = out_cstr1_a.Print("%s", "signed char");
    res_a += out_cstr1_a.Print("%s", "char");
    res_a += out_cstr1_a.Print("%s", "unsigned char");
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<signed char>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<char>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<unsigned char>::CStr()));
    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //integer
    res_a = out_cstr1_a.Print("%s", "short");
    res_a += out_cstr1_a.Print("%s", "int");
    res_a += out_cstr1_a.Print("%s", "long");
    res_a += out_cstr1_a.Print("%s", "long long");
    res_a += out_cstr1_a.Print("%s", "unsigned short");
    res_a += out_cstr1_a.Print("%s", "unsigned int");
    res_a += out_cstr1_a.Print("%s", "unsigned long");
    res_a += out_cstr1_a.Print("%s", "unsigned long long");
    
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<short>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<int>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<long>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<long long>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<unsigned short>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<unsigned int>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<unsigned long>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<unsigned long long>::CStr()));

    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //floating point
    res_a = out_cstr1_a.Print("%s", "float");
    res_a += out_cstr1_a.Print("%s", "double");
    res_a += out_cstr1_a.Print("%s", "long double");
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<float>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<double>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<long double>::CStr()));
    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //value boolean
    res_a = out_cstr1_a.Print("%s", "Obj2<bool, (bool) true>");
    res_a += out_cstr1_a.Print("%s", "Obj2<bool, (bool) false>");
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<bool, true>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<bool, false>>::CStr()));

    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //value character
    res_a = out_cstr1_a.Print("%s %d>", "Obj2<signed char, (signed char)", 
        SCHAR_MIN);
    res_a += out_cstr1_a.Print("%s", "Obj2<char, (char) P>");
    res_a += out_cstr1_a.Print("%s %d>", 
        "Obj2<unsigned char, (unsigned char)", UCHAR_MAX);
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<signed char, SCHAR_MIN>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<char, 'P'>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<unsigned char, UCHAR_MAX>>::CStr()));

    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //value integer
    res_a = out_cstr1_a.Print("%s %d>", "Obj2<short, (short)", 
        SHRT_MIN);
    res_a += out_cstr1_a.Print("%s %u>", 
        "Obj2<unsigned short, (unsigned short)", USHRT_MAX);
    res_a += out_cstr1_a.Print("%s %d>", "Obj2<int, (int)", 
        INT_MIN);
    res_a += out_cstr1_a.Print("%s %u>", 
        "Obj2<unsigned int, (unsigned int)", UINT_MAX);
    res_a += out_cstr1_a.Print("%s %ld>", "Obj2<long, (long)", 
        LONG_MIN);
    res_a += out_cstr1_a.Print("%s %lu>", 
        "Obj2<unsigned long, (unsigned long)", ULONG_MAX);
    res_a += out_cstr1_a.Print("%s %lld>", "Obj2<long long, (long long)", 
        LLONG_MIN);
    res_a += out_cstr1_a.Print("%s %llu>", 
        "Obj2<unsigned long long, (unsigned long long)", ULLONG_MAX);
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<short, SHRT_MIN>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<unsigned short, USHRT_MAX>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<int, INT_MIN>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<unsigned int, UINT_MAX>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<long, LONG_MIN>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<unsigned long, ULONG_MAX>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<long long, LLONG_MIN>>::CStr()));
    res_b += out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<unsigned long long, ULLONG_MAX>>::CStr()));

    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    //value nullptr
    
    res_a = out_cstr1_a.Print("%s", "Obj2<std::nullptr_t, "
        "(std::nullptr_t) nullptr>");
    res_b = out_cstr1_b.Print("%s", 
        *(test::type::Name<Obj2<std::nullptr_t, nullptr>>::CStr()));
        
    assert(res_a == res_b);
    assert(out_cstr1_a.Size() == out_cstr1_b.Size());
    assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
        out_cstr1_a.Size()) == 0);

    return TEST::GetInstance().Status().Get();
}
