#ifndef TEST_SYS_DBG_TYPE_MAKE_H_
#define TEST_SYS_DBG_TYPE_MAKE_H_

#include "../../Type.defn.h"
#include "../Value.h"
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

template<typename TArg, typename... TArgs>
struct Make<test::sys::dbg::Type<TArg>, TArgs...>
{
    typedef test::sys::dbg::type::Parameter<
        test::sys::dbg::Type<TArg>, TArgs...> Type;
};

template<typename TArg, TArg VArg, typename... TArgs>
struct Make<test::sys::dbg::type::Value<TArg, VArg>, TArgs...>
{
    typedef test::sys::dbg::type::Parameter<
        test::sys::dbg::type::Value<TArg, VArg>, TArgs...> Type;
};

} //!param

} //!type

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_TYPE_MAKE_H_
