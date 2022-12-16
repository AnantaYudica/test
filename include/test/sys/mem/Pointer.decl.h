#ifndef TEST_SYS_MEM_POINTER_H_DECL_
#define TEST_SYS_MEM_POINTER_H_DECL_

#include "../Debug.h"

namespace test
{
namespace sys
{
namespace mem
{

template<typename TBlock>
class Pointer;

} //!mem

} //!sys

} //!test

#ifndef TEST_SYS_MEM_POINTER_DLEVEL

#define TEST_SYS_MEM_POINTER_DLEVEL 2

#endif //!TEST_SYS_MEM_POINTER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBlock>

template<typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_MEM_POINTER_DLEVEL, 
    "test::sys::mem::Pointer", 
    test::sys::mem::Pointer<TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_SYS_MEM_POINTER_H_DECL_
