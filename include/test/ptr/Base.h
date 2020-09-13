#ifndef TEST_PTR_BASE_H_
#define TEST_PTR_BASE_H_

#include "Flag.h"
#include "Definition.h"
#include "Block.h"

#include <cstdint>
#include <atomic>
#include <cstddef>
#include <utility>

namespace test
{
namespace ptr
{

class Base
{
private:
    typedef std::size_t IntegerCountType;
    typedef std::atomic<IntegerCountType> CountType;
    typedef test::ptr::Flag FlagType;
    typedef test::ptr::FlagIntegerType FlagIntegerType;
    typedef test::ptr::Block BlockType;
    template<typename T, T(*Func)()>
    using DefinitionType = test::ptr::Definition<T, Func>;
private:
    static inline void _Reset(CountType*& count, BlockType& block);
private:
    std::size_t * m_offset;
    CountType * m_count;
    BlockType m_block;
protected:
    inline Base();
public:
    inline ~Base();
protected:
    inline Base(const Base& cpy);
    inline Base(Base&& mov);
protected:
    inline Base& operator=(const Base& cpy);
    inline Base& operator=(Base&& mov);
protected:
    template<typename T, T(*Func)()>
    inline void* Allocation(const FlagIntegerType& flag,
        const std::size_t& type_size, const std::size_t& type_count,
        DefinitionType<T, Func> * defn);
    inline void Deallocation();
protected:
    template<typename T>
    inline T* Get();
    template<typename T>
    inline T* Get() const;
protected:
    inline FlagIntegerType GetFlag() const;
    inline std::size_t GetOffset() const;
    inline IntegerCountType GetCount() const;
    inline std::size_t GetTypeSize() const;
    inline std::size_t GetDataSize() const;
    inline void* GetData();
protected:
    inline void SetOffset(const std::size_t& size);
protected:
    inline Base& operator+=(const std::size_t& size);
    inline Base& operator-=(const std::size_t& size);
protected:
    inline Base& operator++();
    inline Base operator++(int);
protected:
    inline Base& operator--();
    inline Base operator--(int);
protected:
    inline Base operator+(const std::size_t& size);
    inline Base operator-(const std::size_t& size);
protected:
    inline bool operator==(const Base& other) const;
    inline bool operator!=(const Base& other) const;
protected:
    inline bool operator==(void* other) const;
    inline bool operator!=(void* other) const;
protected:
    inline operator bool() const;
};

inline void Base::_Reset(CountType *& count, BlockType& block)
{
    const auto is_count_null = (count == nullptr);
    if (!is_count_null && *count == 1)
    {
        delete count;
        block.Deallocation();
    }
    else if(!is_count_null)
    {
        (*count)--; 
        block = BlockType{};
    }
    count = nullptr;
}

inline Base::Base() :
    m_offset(new std::size_t(0)),
    m_count(nullptr),
    m_block()
{}

inline Base::~Base()
{
    _Reset(m_count, m_block);
    delete m_offset;
    m_offset = nullptr;
}

inline Base::Base(const Base& cpy) :
    m_offset(new std::size_t(*(cpy.m_offset))),
    m_count(cpy.m_count),
    m_block(cpy.m_block)
{
    if (m_count != nullptr) (*m_count)++;
}

inline Base::Base(Base&& mov) :
    m_offset(new std::size_t(*(mov.m_offset))),
    m_count(mov.m_count),
    m_block(std::move(mov.m_block))
{
    *(mov.m_offset) = 0;
    mov.m_count = nullptr;
    mov.m_block = Block{};
}

inline Base& Base::operator=(const Base& cpy)
{
    _Reset(m_count, m_block);
    *m_offset = *(cpy.m_offset);
    m_count = cpy.m_count;
    m_block = cpy.m_block;
    if (m_count != nullptr) (*m_count)++;
    return *this;
}

inline Base& Base::operator=(Base&& mov)
{
    _Reset(m_count, m_block);
    *m_offset = *(mov.m_offset);
    m_count = mov.m_count;
    m_block = mov.m_block;

    *(mov.m_offset) = 0;
    mov.m_count = nullptr;
    mov.m_block = Block{};
    return *this;
}

template<typename T, T(*Func)()>
inline void* Base::Allocation(const FlagIntegerType& flag,
    const std::size_t& type_size, const std::size_t& type_count,
    DefinitionType<T, Func> * defn)
{
    _Reset(m_count, m_block);
    *m_offset = 0;
    m_count = new CountType(1);
    return m_block.Allocation(flag, type_size, type_count, defn);
}

inline void Base::Deallocation()
{
    *m_offset = 0;
    _Reset(m_count, m_block);
}

template<typename T>
inline T* Base::Get()
{
    char * data = (char *)m_block.GetData();
    return reinterpret_cast<T*>(data + *m_offset);
}

template<typename T>
inline T* Base::Get() const
{
    char * data = (char *) const_cast<Block&>(m_block).GetData();
    return reinterpret_cast<T*>(data + *m_offset);
}

inline typename Base::FlagIntegerType Base::GetFlag() const
{
    return const_cast<BlockType&>(m_block).GetFlag();
}

inline std::size_t Base::GetOffset() const
{
    return *m_offset;
}

inline typename Base::IntegerCountType Base::GetCount() const
{
    return m_count == nullptr ? 0 : IntegerCountType(*m_count);
}

inline std::size_t Base::GetTypeSize() const
{
    return const_cast<BlockType&>(m_block).GetTypeSize();
}

inline std::size_t Base::GetDataSize() const
{
    return const_cast<BlockType&>(m_block).GetDataSize();
}

inline void* Base::GetData()
{
    return m_block.GetData();
}

inline void Base::SetOffset(const std::size_t& size)
{
    *m_offset = (size % GetDataSize());
}

inline Base& Base::operator+=(const std::size_t& size)
{
    if (GetDataSize() == 0) return *this;
    *m_offset += size;
    *m_offset %= GetDataSize();
    return *this;
}

inline Base& Base::operator-=(const std::size_t& size)
{
    if (GetDataSize() == 0) return *this;
    const std::size_t rem_size = (size % GetDataSize());
    if (*m_offset >= rem_size)
        *m_offset -= rem_size;
    else
    {
        *m_offset = (rem_size  - *m_offset);
        *m_offset = (GetDataSize() - *m_offset);
    }
    return *this;
}

inline Base& Base::operator++()
{
    *(this) += 1; 
    return *this;
}

inline Base Base::operator++(int)
{
    Base ret{*this};
    *(this) += 1;
    return ret;
}

inline Base& Base::operator--()
{
    *(this) -= 1; 
    return *this;
}

inline Base Base::operator--(int)
{
    Base ret{*this};
    *(this) -= 1; 
    return ret;
}

inline Base Base::operator+(const std::size_t& size)
{
    Base ret{*this};
    ret += size;
    return ret;
}

inline Base Base::operator-(const std::size_t& size)
{
    Base ret{*this};
    ret -= size;
    return ret;
}

inline bool Base::operator==(const Base& other) const
{
    return (const_cast<BlockType&>(m_block).GetData() == 
        const_cast<BlockType&>(other.m_block).GetData()) &&
        *m_offset == *(other.m_offset);
}

inline bool Base::operator!=(const Base& other) const
{
    return !(*this == other);
}

inline bool Base::operator==(void* other) const
{
    return const_cast<BlockType&>(m_block).GetData() == other;
}

inline bool Base::operator!=(void* other) const
{
    return const_cast<BlockType&>(m_block).GetData() != other;
}

inline Base::operator bool() const
{
    return const_cast<BlockType&>(m_block).GetData() != 
        BlockType{}.GetData();
}

} //!ptr

} //!test

#endif //!TEST_PTR_BASE_H_
