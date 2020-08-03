#ifndef TEST_MSG_FMT_VAL_SPECIFIER_VAL_CHARACTER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_VAL_CHARACTER_H_

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

union Character
{
    int char_value;
    std::wint_t wchar_value;
};

} //!val

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_VAL_CHARACTER_H_
