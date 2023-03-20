#ifndef TEST_ARG_BLOCK_H_
#define TEST_ARG_BLOCK_H_

#include "../System.h"
#include "../Pointer.h"
#include "../sys/mem/Dummy.h"
#include "Header.h"
#include "Type.h"

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
    typedef test::Pointer<std::uint8_t> BufferType;
private:
    typedef void (*DestructorFuncType)(Block*, BufferType);
public:
    typedef test::arg::Header HeaderType;
private:
    template<typename T>
    static inline void Destructor(Block* block, BufferType buff);
private:
    HeaderType m_header;
    std::size_t m_off;
    std::size_t m_size;
    DestructorFuncType m_destructor;
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
    template<typename T>
    inline void Initialize(BufferType buff);
    template<typename T>
    inline void Initialize(BufferType buff, T&& val);
public:
    template<typename T>
    inline void Set(BufferType buff, T&& val) const;
    template<typename T>
    inline void Set(BufferType buff, const T& val) const;
    template<typename T>
    inline typename test::arg::Type<T>::RValueType Get(BufferType buff) const;
public:
    inline void Destroy(BufferType buff) const;
public:
    inline bool operator==(const Block& other) const;
    inline bool operator!=(const Block& other) const;
};

template<typename T>
inline void Block::Destructor(Block* block, BufferType buff)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, NULL, 
        "Destructor<%s>(block=%p, buff=%p)", TEST_SYS_DEBUG_T_NAME_STR(T),
            block, buff.GetData());

    buff.SetIndex(block->m_off);
    T& cast = *(buff.template ReinterpretCast<T>());
    cast.~T();
}

inline Block::Block() :
    m_header(),
    m_off(0),
    m_size(0),
    m_destructor(nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Block::Block(const HeaderType& header, const std::size_t& off, 
    const std::size_t& size) :
        m_header(header),
        m_off(off),
        m_size(size),
        m_destructor(nullptr)
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

template<typename T>
inline void Block::Initialize(BufferType buff)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Initialize<%s>(buff=%p)", TEST_SYS_DEBUG_T_NAME_STR(T),
            buff.GetData());

    buff.SetIndex(m_off);
    
    new (&*(buff.template ReinterpretCast<T>()))T();

    m_destructor = Destructor<T>;
}

template<typename T>
inline void Block::Initialize(BufferType buff, T&& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Initialize<%s>(buff=%p, val=%s)", TEST_SYS_DEBUG_T_NAME_STR(T),
            buff.GetData(), TEST_SYS_DEBUG_VALUE_STR(0, val));

    buff.SetIndex(m_off);
    
    new (&*(buff.template ReinterpretCast<T>()))T(std::forward<T>(val));

    m_destructor = Destructor<T>;
}

template<typename T>
inline void Block::Set(BufferType buff, T&& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(buff=%p, val=%s)", 
        TEST_SYS_DEBUG_T_NAME_STR(T),
        buff.GetData(), TEST_SYS_DEBUG_VALUE_STR(0, val));

    typedef test::arg::Type<T> Type;
    
    if (Type::Size > m_size || m_size == 0)
    {
        return;
    }

    buff.SetIndex(m_off);
    return Type::Set(buff, std::move(val));
}

template<typename T>
inline void Block::Set(BufferType buff, const T& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(buff=%p, val=%s)", 
        TEST_SYS_DEBUG_T_NAME_STR(T),
        buff.GetData(), TEST_SYS_DEBUG_VALUE_STR(0, val));
    
    typedef test::arg::Type<T> Type;

    if (Type::Size > m_size || m_size == 0)
    {
        return;
    }

    buff.SetIndex(m_off);
    return Type::Set(buff, val);
}

template<typename T>
inline typename test::arg::Type<T>::RValueType 
Block::Get(BufferType buff) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Get<%s>(buff=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), buff.GetData());

    typedef test::arg::Type<T> Type;

    buff.SetIndex(m_off);
    return Type::Get(buff);
}

inline void Block::Destroy(BufferType buff) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Destroy(buff=%p)", buff.GetData());

    if (m_destructor == nullptr)
    {
        return;
    }

    (*m_destructor)(const_cast<Block*>(this), buff);
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
