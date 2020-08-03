#ifndef TEST_MSG_FMT_PARAM_SPECIFIER_VAL_NOTHING_H_
#define TEST_MSG_FMT_PARAM_SPECIFIER_VAL_NOTHING_H_

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

union Nothing
{
    char* char_value;
    short* short_value;
    int* int_value;
    long* long_value;
    long long* long_long_value;
};

} //!val

} //!specifier

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_SPECIFIER_VAL_NOTHING_H_
