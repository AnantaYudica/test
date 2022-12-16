#ifndef TEST_SYS_MEM_PTR_CONST_CAST_H_DECL_
#define TEST_SYS_MEM_PTR_CONST_CAST_H_DECL_

#include "../../../Debug.h"

namespace test
{
namespace sys
{
namespace mem
{
namespace ptr
{
namespace cast
{

template<typename T, typename TBlock>
class Const;

} //!cast

} //!ptr

} //!mem

} //!sys

} //!test

#ifndef TEST_SYS_MEM_PTR_CONST_CAST_DLEVEL

#define TEST_SYS_MEM_PTR_CONST_CAST_DLEVEL 2

#endif //!TEST_SYS_MEM_PTR_CONST_CAST_DLEVEL


#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TBlock>

template<typename T, typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_MEM_PTR_CONST_CAST_DLEVEL, 
    "test::sys::mem::ptr::cast::Const", 
    test::sys::mem::ptr::cast::Const<T, TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_SYS_MEM_PTR_CONST_CAST_H_DECL_
