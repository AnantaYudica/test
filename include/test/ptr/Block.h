#ifndef TEST_PTR_BLOCK_H_
#define TEST_PTR_BLOCK_H_

#include "Flag.h"
#include "block/Header.h"

#include <cstdint>

namespace test
{
namespace ptr
{

class Block
{
public:
    typedef test::ptr::block::Header HeaderType;
    typedef test::ptr::FlagIntegerType FlagIntegerType;
private:
    char * m_value;
private:
    static inline char * _Default();
public:
    inline Block();
public:
    inline ~Block();
public:
    inline Block(const Block& cpy);
    inline Block(Block&& mov);
public:
    inline Block& operator=(const Block& cpy);
    inline Block& operator=(Block&& mov);
public:
    inline void * Allocation(const std::size_t& size);
    inline void Deallocation();
public:
    inline FlagIntegerType* GetFlag();
    inline std::size_t* GetSize();
    inline void* GetData();
};

inline char * Block::_Default()
{
    static char _value[sizeof(HeaderType) + 1];
    return _value;
}

inline Block::Block() :
    m_value(_Default())
{}

inline Block::~Block()
{
    m_value = _Default();
}

inline Block::Block(const Block& cpy) :
    m_value(cpy.m_value)
{}

inline Block::Block(Block&& mov) :
    m_value(mov.m_value)
{
    mov.m_value = _Default();
}

inline Block& Block::operator=(const Block& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline Block& Block::operator=(Block&& mov)
{
    m_value = mov.m_value;
    mov.m_value = _Default();
    return *this;
}

inline void * Block::Allocation(const std::size_t& size)
{
    m_value = new char[sizeof(HeaderType) + size];
    *GetFlag() = 0;
    *GetSize() = size;
    return GetData();
}

inline void Block::Deallocation()
{
    delete[] m_value;
    m_value = _Default();
}

inline FlagIntegerType* Block::GetFlag()
{
    return &(((HeaderType*)m_value)->flag);
}

inline std::size_t* Block::GetSize()
{
    return &(((HeaderType*)m_value)->size);
}

inline void* Block::GetData()
{
    return (void*)(m_value + sizeof(HeaderType));
}

} //!ptr

} //!test

#endif //!TEST_PTR_BLOCK_H_