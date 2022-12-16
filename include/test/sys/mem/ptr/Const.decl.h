#ifndef TEST_SYS_MEM_PTR_CONST_H_DECL_
#define TEST_SYS_MEM_PTR_CONST_H_DECL_

#include "../../Debug.h"

namespace test
{
namespace sys
{
namespace mem
{
namespace ptr
{

template<typename TBlock>
class Const;

} //!ptr

} //!mem

} //!sys

} //!test

#ifndef TEST_SYS_MEM_PTR_CONST_DLEVEL

#define TEST_SYS_MEM_PTR_CONST_DLEVEL 2

#endif //!TEST_SYS_MEM_PTR_CONST_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBlock>

template<typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(TEST_SYS_MEM_PTR_CONST_DLEVEL, 
    "test::sys::mem::ptr::Const", 
    test::sys::mem::ptr::Const<TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_SYS_MEM_PTR_CONST_H_DECL_
