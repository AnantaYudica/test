#ifndef TEST_OUT_BASE_TASK_BASE_H_
#define TEST_OUT_BASE_TASK_BASE_H_

#include "base/imp/Default.h"

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TChar>
using Base = test::out::base::task::base::imp::Default<TChar>;

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_BASE_H_
