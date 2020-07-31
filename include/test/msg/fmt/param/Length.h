#ifndef TEST_MSG_FMT_PARAM_LENGTH_H_
#define TEST_MSG_FMT_PARAM_LENGTH_H_

#include "Precision.h"

namespace test
{
namespace msg
{
namespace fmt
{
namespace param
{

template<typename TChar>
using Length = test::msg::fmt::param::Precision<TChar>;

} //!param

} //!fmt

} //!msg

} //!test


#endif //!TEST_MSG_FMT_PARAM_LENGTH_H_