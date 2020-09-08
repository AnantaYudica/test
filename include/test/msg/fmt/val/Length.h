#ifndef TEST_MSG_FMT_VAL_LENGTH_H_
#define TEST_MSG_FMT_VAL_LENGTH_H_

#include "Precision.h"

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{

template<typename TChar>
using Length = test::msg::fmt::val::Precision<TChar>;

} //!val

} //!fmt

} //!msg

} //!test


#endif //!TEST_MSG_FMT_VAL_LENGTH_H_