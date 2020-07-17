#ifndef TEST_MSG_FMT_PARAM_SPECIFIER_VAL_CHARACTER_H_
#define TEST_MSG_FMT_PARAM_SPECIFIER_VAL_CHARACTER_H_

#include <cwchar>

namespace test
{
namespace msg
{
namespace fmt
{
namespace param
{
namespace specifier
{
namespace val
{

union Character
{
    unsigned char char_value;
    std::wint_t wchar_value;
};

} //!val

} //!specifier

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_SPECIFIER_VAL_CHARACTER_H_
