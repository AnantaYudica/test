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
struct test::type::Name<A<TArgs...>>
{
    static test::CString<char> CStr()
    {
        test::CString<char> param = 
            std::move(test::type::param::Name<
                test::type::Parameter<TArgs...>>::CStr());
        return test::cstr::Format<char>(4 + (param.Size() - 1),
            "A<%s>", *param);
    }
};

TEST_TYPE_NAME("int", int);

int main()
{
    test::CString<char> ch1 = 
        std::move(test::type::Name<A<int, int, int>>::CStr());
    printf("%s\n", *ch1);
}
