#ifndef TEST_MSG_FMT_PARAM_SPECIFIER_VAL_INTEGER_H_
#define TEST_MSG_FMT_PARAM_SPECIFIER_VAL_INTEGER_H_

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

union Integer
{
    char char_value;
    short short_value;
    int int_value;
    long long_value;
    long long long_long_value;
    unsigned char unsigned_char_value;
    unsigned short unsigned_short_value;
    unsigned int unsigned_int_value;
    unsigned long unsigned_long_value;
    unsigned long long unsigned_long_long_value;
};

} //!val

} //!specifier

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_SPECIFIER_VAL_INTEGER_H_
