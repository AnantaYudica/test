#ifndef TEST_OUT_FMT_OUT_BLOCK_H_
#define TEST_OUT_FMT_OUT_BLOCK_H_

#include "../../../System.h"
#include "../Definition.h"

#include <utility>
#include <type_traits>
#include <cstdlib>

namespace test
{
namespace out
{
namespace fmt
{
namespace out
{

class Block;

} //!out

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_OUT_BLOCK_DLEVEL

#define TEST_OUT_FMT_OUT_BLOCK_DLEVEL 2

#endif //!TEST_OUT_FMT_OUT_BLOCK_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_OUT_BLOCK_DLEVEL, 
    "test::out::fmt::out::Block", test::out::fmt::out::Block);

namespace test
{
namespace out
{
namespace fmt
{
namespace out
{

class Block
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::out::Block> DebugType;
public:
    typedef test::out::fmt::Definition DefinitionType;
    typedef typename DefinitionType::OutputIntegerType OutputIntegerType;
    template<typename TChar>
    using FormatOutputFuncType = DefinitionType::FormatOutputFuncType<TChar>;
private:
    OutputIntegerType m_type;
    void* m_pointer;
public:
    inline Block();
    template<typename TChar>
    inline Block(FormatOutputFuncType<TChar> func);
    inline ~Block();
public:
    inline Block(const Block& cpy);
    inline Block(Block&& mov);
public:
    inline Block& operator=(const Block& cpy);
    inline Block& operator=(Block&& mov);
public:
    inline OutputIntegerType GetType() const;
public:
    template<typename TChar>
    inline FormatOutputFuncType<TChar> GetFormatOutput() const;
};

inline Block::Block() :
    m_type(DefinitionType::output_undefined),
    m_pointer(nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
}

template<typename TChar>
inline Block::Block(FormatOutputFuncType<TChar> func) :
    m_type(DefinitionType::OutputValue((TChar)0)),
    m_pointer((void*)func)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(func=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TChar), func);
}

inline Block::Block(const Block& cpy) :
    m_type(cpy.m_type),
    m_pointer(cpy.m_pointer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
}

inline Block::Block(Block&& mov) :
    m_type(mov.m_type),
    m_pointer(mov.m_pointer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_type = DefinitionType::output_undefined;
    mov.m_pointer = nullptr;
}

inline Block::~Block()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor()");

    m_type = DefinitionType::output_undefined;
    m_pointer = nullptr;
}

inline Block& Block::operator=(const Block& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_type = cpy.m_type;
    m_pointer = cpy.m_pointer;
    return *this;
}

inline Block& Block::operator=(Block&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_type = mov.m_type;
    m_pointer = mov.m_pointer;
    
    mov.m_type = DefinitionType::output_undefined;
    mov.m_pointer = nullptr;
    return *this;
}

inline typename Block::OutputIntegerType Block::GetType() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetType() const");

    return m_type;
}

template<typename TChar>
inline typename Block::FormatOutputFuncType<TChar> Block::GetFormatOutput() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetFormatOutput<%s>() const", TEST_SYS_DEBUG_T_NAME_STR(TChar));

    const OutputIntegerType out_type = 
        DefinitionType::OutputValue((TChar)0);
    if (out_type == m_type)
    {
        return reinterpret_cast<FormatOutputFuncType<TChar>>(m_pointer);
    }
    return nullptr;
}

} //!out

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_OUT_BLOCK_H_
