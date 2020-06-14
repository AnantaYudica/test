#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/Format.h"

#include <cstdio>

char _true_cstr[] = "true";
char _false_cstr[] = "false";

#define PRINT_FORMAT(__VAR_NAME__)\
printf("name : %s, size : %d, cstr : \"%s\", IsNull : %s, IsEmpty : %s\n",\
    #__VAR_NAME__, __VAR_NAME__.Size(), *__VAR_NAME__,\
    (!__VAR_NAME__ ? _true_cstr : _false_cstr),\
    (__VAR_NAME__.IsEmpty() ? _true_cstr : _false_cstr))


int main()
{
    test::msg::Format<char> f1;
    PRINT_FORMAT(f1);

    test::msg::Format<char> f1_1("");
    PRINT_FORMAT(f1_1);

    test::msg::Format<char> f2("format : %s");
    PRINT_FORMAT(f2);

    test::msg::Format<char> f3(f2, f2.Size() + 4, "%s::%s");
    PRINT_FORMAT(f3);

    test::msg::Format<char> f4(f2, f2.Size() + 25, 
        "Type<%s>", "template Foo1<%s>(%s)");
    PRINT_FORMAT(f4);

    test::msg::Format<char> f5("format : %d");
    PRINT_FORMAT(f5);
    
    test::msg::Format<char> f6(f5, f5.Size() + 10, 4);
    PRINT_FORMAT(f6);

    test::msg::Format<char> f7(f4);
    PRINT_FORMAT(f7);

    test::msg::Format<char> f8(std::move(f7));
    PRINT_FORMAT(f8);
    PRINT_FORMAT(f7);

    test::msg::Format<char> f9("test");
    PRINT_FORMAT(f9);
    f9 = f4;
    PRINT_FORMAT(f9);

    test::msg::Format<char> f10;
    f10 = std::move(f9);
    PRINT_FORMAT(f10);
    PRINT_FORMAT(f9);

    test::msg::Format<char> f11("testddd : %d", 14);
    PRINT_FORMAT(f11);

    test::msg::Format<char> f12(test::CString<char>("test cstr"));
    PRINT_FORMAT(f12);

    test::msg::Format<char> f13(test::CString<const char>("test cstr const"));
    PRINT_FORMAT(f13);
    
    test::msg::Format<char> f14(std::move(test::CString<char>("test cstr")));
    PRINT_FORMAT(f14);

    test::msg::Format<char> f15(std::move(test::CString<const char>("test cstr const")));
    PRINT_FORMAT(f15);
}
