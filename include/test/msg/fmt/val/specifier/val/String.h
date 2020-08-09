#ifndef TEST_MSG_FMT_VAL_SPECIFIER_VAL_STRING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_VAL_STRING_H_

#include <cwchar>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{
namespace specifier
{
namespace val
{

union String
{
    const char * char_ptr_value;
    const wchar_t * wchar_ptr_value;
};

} //!val

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_VAL_STRING_H_
