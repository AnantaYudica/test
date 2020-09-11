#ifndef TEST_PTR_BLOCK_H_
#define TEST_PTR_BLOCK_H_

#include "Flag.h"
#include "block/Header.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace ptr
{

class Block
{
public:
    typedef test::ptr::block::Header HeaderType;
    typedef typename HeaderType::DestructorFuncType DestructorFuncType;
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
    inline void * Allocation(const FlagIntegerType& flag, 
        const std::size_t& type_size, const std::size_t& type_count,
        DestructorFuncType& destructor);
    inline void Deallocation();
public:
    inline FlagIntegerType GetFlag() const;
    inline std::size_t GetTypeSize() const;
    inline std::size_t GetDataSize() const;
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

inline void * Block::Allocation(const FlagIntegerType& flag, 
    const std::size_t& type_size, const std::size_t& type_count,
    DestructorFuncType& destructor)
{
    const std::size_t data_size = type_size * type_count;
    m_value = new char[sizeof(HeaderType) + data_size];
    HeaderType * header = (HeaderType*)m_value;
    header->flag = flag;
    header->destructor = &destructor;
    header->type_size = type_size;
    header->data_size = data_size;
    return GetData();
}

inline void Block::Deallocation()
{
    if (m_value == _Default()) return;
    HeaderType * header = (HeaderType*)m_value;
    const auto type_size = GetTypeSize();
    const auto data_size = GetDataSize();
    char * data = (char *)GetData();
    for (size_t i = 0; i < data_size;)
    {
        (*header->destructor)(data);
        data += type_size;
        i += type_size;
    }
    delete[] m_value;
    m_value = _Default();
}

inline FlagIntegerType Block::GetFlag() const
{
    return ((HeaderType*)m_value)->flag;
}

inline std::size_t Block::GetTypeSize() const
{
    return ((HeaderType*)m_value)->type_size;
}

inline std::size_t Block::GetDataSize() const
{
    return ((HeaderType*)m_value)->data_size;
}

inline void* Block::GetData()
{
    return (void*)(m_value + sizeof(HeaderType));
}

} //!ptr

} //!test

#endif //!TEST_PTR_BLOCK_H_
