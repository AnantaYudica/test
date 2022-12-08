#ifndef TEST_SYS_DBG_TYPE_MAKE_H_
#define TEST_SYS_DBG_TYPE_MAKE_H_

#include "../../Type.defn.h"
#include "../Parameter.h"

namespace test
{
namespace sys
{
namespace dbg
{
namespace type
{
namespace param
{

template<typename... TArgs>
struct Make
{
    typedef test::sys::dbg::type::Parameter<
        test::sys::dbg::Type<TArgs>...> Type;
};

} //!param

} //!type

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_TYPE_MAKE_H_
