#ifndef TEST_OUT_FMT_VAL_STRUCTURE_H_
#define TEST_OUT_FMT_VAL_STRUCTURE_H_

#include "../../../System.h"
#include "../../../Pointer.h"
#include "../Definition.h"
#include "../Block.h"
#include "Structure.h"

#include <cstdarg>
#include <utility>
#include <mutex>

namespace test
{
namespace out
{
namespace fmt
{
namespace val
{

template<typename TStatus>
struct Structure
{
public:
    typedef TStatus StatusType;
public:
    typedef test::Pointer<test::out::fmt::Block> BlocksType;
public:
    typedef test::Pointer<char> RawType;
public:
    StatusType m_status;
    std::mutex m_lock;
    std::size_t m_loadSize;
    BlocksType m_blocks;
    RawType m_raw;
public:
    Structure() :
        m_status(),
        m_lock(),
        m_loadSize(0),
        m_blocks(nullptr),
        m_raw(nullptr)
    {}
};

} //!val

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_VAL_STRUCTURE_DLEVEL

#define TEST_OUT_FMT_VAL_STRUCTURE_DLEVEL 2

#endif //!TEST_OUT_FMT_VAL_STRUCTURE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>

template<typename TStatus>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_VAL_STRUCTURE_DLEVEL, 
    "test::out::fmt::val::Structure", 
    test::out::fmt::val::Structure<TStatus>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_OUT_FMT_VAL_STRUCTURE_H_
