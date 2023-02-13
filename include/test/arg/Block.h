#ifndef TEST_ARG_BLOCK_H_
#define TEST_ARG_BLOCK_H_

#include "../System.h"
#include "../Pointer.h"
#include "../sys/mem/Dummy.h"
#include "Header.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace arg
{

class Block;

} //!arg

} //!test

#ifndef TEST_ARG_BLOCK_DLEVEL

#define TEST_ARG_BLOCK_DLEVEL 2

#endif //!TEST_ARG_BLOCK_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_ARG_BLOCK_DLEVEL, 
    "test::arg::Block", test::arg::Block);

namespace test
{
namespace arg
{

class Block
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::Block> DebugType;
public:
    typedef test::arg::Header HeaderType;
private:
    HeaderType m_header;
    std::size_t m_off;
    std::size_t m_size;
public:
    inline Block();
    inline Block(const HeaderType& header, const std::size_t& off, 
        const std::size_t& size);
    inline ~Block();
public:
    inline Block(const Block& cpy);
    inline Block(Block&& mov);
public:
    inline Block& operator=(const Block& cpy);
    inline Block& operator=(Block&& mov);
public:
    inline void SetHeader(const HeaderType& header);
    inline HeaderType GetHeader() const;
public:
    inline void SetOffset(const std::size_t& off);
    inline std::size_t GetOffset() const;
public:
    inline void SetSize(const std::size_t& size);
    inline std::size_t GetSize() const;
public:
    template<typename T, typename TP, typename TD>
    inline void Set(test::Pointer<TP, TD> blocks, T&& val) const;
    template<typename T, typename TP, typename TD>
    inline void Set(test::Pointer<TP, TD> blocks, const T& val) const;
    template<typename T, typename TP, typename TD>
    inline T Get(test::Pointer<TP, TD> blocks) const;
public:
    inline bool operator==(const Block& other) const;
    inline bool operator!=(const Block& other) const;
};

inline Block::Block() :
    m_header(),
    m_off(0),
    m_size(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Block::Block(const HeaderType& header, const std::size_t& off, 
    const std::size_t& size) :
        m_header(header),
        m_off(off),
        m_size(size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(header=%x, off=%zu, size=%zu)", header.Flag(), off, size);

}

inline Block::~Block()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_off = 0;
    m_size = 0;
}

inline Block::Block(const Block& cpy) :
    m_header(cpy.m_header),
    m_off(cpy.m_off),
    m_size(cpy.m_size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

inline Block::Block(Block&& mov) :
    m_header(std::move(mov.m_header)),
    m_off(mov.m_off),
    m_size(mov.m_size)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_off = 0;
    mov.m_size = 0;
}

inline Block& Block::operator=(const Block& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_header = cpy.m_header;
    m_off = cpy.m_off;
    m_size = cpy.m_size;
    return *this;
}

inline Block& Block::operator=(Block&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_header = std::move(mov.m_header);
    m_off = mov.m_off;
    m_size = mov.m_size;
    mov.m_off = 0;
    mov.m_size = 0;
    return *this;
}

inline void Block::SetHeader(const HeaderType& header)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetHeader(header=%x)", header.Flag());
    
    m_header = header;
}

inline typename Block::HeaderType Block::GetHeader() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetHeader() const");
    
    return m_header;
}

inline void Block::SetOffset(const std::size_t& off)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetOffset(off=%zu)", off);
    
    m_off = off;
}

inline std::size_t Block::GetOffset() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetOffset() const");

    return m_off;
}

inline void Block::SetSize(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetSize(size=%zu)", size);
    
    m_size = size;
}

inline std::size_t Block::GetSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetSize() const");

    return m_size;
}

template<typename T, typename TP, typename TD>
inline void Block::Set(test::Pointer<TP, TD> blocks, T&& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(blocks=%p, val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T, TP, TD),
        &blocks, TEST_SYS_DEBUG_VALUE_STR(0, val));
    
    if (sizeof(T) > m_size || m_size == 0)
    {
        return;
    }

    blocks.SetIndex(m_off);
    *(blocks.template ReinterpretCast<T>()) = val;
}

template<typename T, typename TP, typename TD>
inline void Block::Set(test::Pointer<TP, TD> blocks, const T& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(blocks=%p, val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T, TP, TD),
        &blocks, TEST_SYS_DEBUG_VALUE_STR(0, val));
    
    if (sizeof(T) > m_size || m_size == 0)
    {
        return;
    }

    blocks.SetIndex(m_off);
    *(blocks.template ReinterpretCast<T>()) = val;
}

template<typename T, typename TP, typename TD>
inline T Block::Get(test::Pointer<TP, TD> blocks) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Get<%s>(blocks=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T, TP, TD), &blocks);

    blocks.SetIndex(m_off);
    return *(blocks.template ReinterpretCast<T>());
}

inline bool Block::operator==(const Block& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p)", &other);
    
    return m_header == other.m_header &&
        m_off == other.m_off &&
        m_size == other.m_size;
}

inline bool Block::operator!=(const Block& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p)", &other);
    
    return !(*this == other);
}

} //!arg

} //!test

#endif //!TEST_ARG_BLOCK_H_
