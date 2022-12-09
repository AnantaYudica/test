#ifndef TEST_SYS_MEM_PTR_CAST_H_DECL_
#define TEST_SYS_MEM_PTR_CAST_H_DECL_

#include "../../Debug.h"

namespace test
{
namespace sys
{
namespace mem
{
namespace ptr
{

template<typename T, typename TBlock>
class Cast;

} //!ptr

} //mem

} //!sys

} //!test

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TBlock>

template<typename T, typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::sys::mem::ptr::Cast", 
    test::sys::mem::ptr::Cast<T, TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_SYS_MEM_PTR_CAST_H_DECL_
