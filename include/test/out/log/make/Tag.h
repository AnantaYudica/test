#ifndef TEST_OUT_LOG_MAKE_TAG_H_
#define TEST_OUT_LOG_MAKE_TAG_H_

#include "../Tag.h"

namespace test
{
namespace out
{
namespace log
{
namespace make
{

template<typename TChar>
inline test::out::log::Tag<TChar> Tag(...)
{
    return {};
}

} //!make

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_MAKE_TAG_H_
