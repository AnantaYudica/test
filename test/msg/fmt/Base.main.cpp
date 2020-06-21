#include "test/msg/fmt/Base.h"
#include "test/msg/Argument.h"
#include "test/msg/arg/type/Name.h"
#include "test/Variable.h"
#include "test/type/Value.h"
#include "test/Value.h"
#include "test/type/Name.h"

#include <cassert>

template<>
struct test::type::Name<int>
{
    static test::CString<const char> CStr()
    {
        static char _cstr[] = "int";
        return {_cstr};
    }
};

struct TestA1 {};

typedef test::msg::Argument<TestA1, 
    test::msg::arg::type::Name<0>> ArgTestA1;

typedef test::Variable<int, test::type::Value<int, 2>,
        test::Value<const char*>> Var1;

typedef test::msg::fmt::Base<char, Var1, ArgTestA1> FormatBase;

struct Format1 : FormatBase
{
    Format1() :
        FormatBase()
    {};
    ~Format1()
    {}
    FormatBase & operator=(const FormatBase&)
    {
        return *this;
    }
    FormatBase & operator=(FormatBase&&)
    {
        return *this;
    }
    typename FormatBase::SizeType Puts(test::out::CString<char>& out_cstr, 
        Var1 & var) const
    {
        auto cstr = ArgTestA1{}.Get(var);
        return out_cstr.Puts(cstr);
    }
};

struct Format2 : Format1
{
    test::CString<char> m_prefix;
    template<int S>
    Format2(const char (&prefix)[S]) :
        Format1(),
        m_prefix(prefix)
    {};
    ~Format2()
    {}
    FormatBase & operator=(const FormatBase&)
    {
        return *this;
    }
    FormatBase & operator=(FormatBase&&)
    {
        return *this;
    }
    typename FormatBase::SizeType Puts(test::out::CString<char>& out_cstr, 
        Var1 & var) const
    {
        return out_cstr.Puts(m_prefix) + Format1::Puts(out_cstr, var);
    }
};

int main()
{
    const char * cstr1 = "test";
    Var1 v1{2, 4, cstr1};
    
    Format1 f1;
    test::out::CString<char> out_cstr1;
    f1.Puts(out_cstr1, v1);
    assert(strncmp((*out_cstr1.Get()), "int", 3) == 0);

    FormatBase * f2 = new Format2("type : ");
    test::out::CString<char> out_cstr2;
    f2->Puts(out_cstr2, v1);
    delete f2;
    assert(strncmp((*out_cstr2.Get()), "type : int", 10) == 0);

    return 1;
}