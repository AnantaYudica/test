#ifndef TEST_MSG_FMT_VAL_SPECIFIER_VAL_NOTHING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_VAL_NOTHING_H_

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

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_VAL_NOTHING_H_
