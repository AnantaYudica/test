#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/CString.h"
#include "test/cstr/Format.h"
#include "test/type/Name.h"
#include "test/type/param/Name.h"

#include <cstdio>

template<typename... TArgs>
struct A
{};

template<typename... TArgs>
struct basic::test::type::Name<A<TArgs...>>
{
    static basic::test::CString<char> CStr()
    {
        basic::test::CString<char> param = 
            std::move(basic::test::type::param::Name<
                basic::test::type::Parameter<TArgs...>>::CStr());
        return basic::test::cstr::Format<char>(4 + (param.Size() - 1),
            "A<%s>", *param);
    }
};

TEST_TYPE_NAME("int", int);

int main()
{
    basic::test::CString<char> ch1 = 
        std::move(basic::test::type::Name<A<int, int, int>>::CStr());
    printf("%s\n", *ch1);
}
