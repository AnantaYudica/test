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

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBlock>

template<typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::sys::mem::ptr::Const", 
    test::sys::mem::ptr::Const<TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_SYS_MEM_PTR_CONST_H_DECL_
