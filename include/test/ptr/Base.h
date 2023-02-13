#ifndef TEST_PTR_BASE_H_
#define TEST_PTR_BASE_H_

#include "Flag.h"
#include "Definition.h"
#include "Block.h"
#include "../sys/mem/Dummy.h"

#include <cstdint>
#include <atomic>
#include <cstddef>
#include <utility>

namespace test
{
namespace ptr
{

class Base;

} //!ptr

} //!test

#ifndef TEST_PTR_BASE_DLEVEL

#define TEST_PTR_BASE_DLEVEL 2

#endif //!TEST_PTR_BASE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_PTR_BASE_DLEVEL, 
    "test::ptr::Base", test::ptr::Base);

namespace test
{
namespace ptr
{

class Base
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::ptr::Base> DebugType;
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
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "_Reset(count=%p, block%p)", count, &block);

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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Base::~Base()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    _Reset(m_count, m_block);
    delete m_offset;
    m_offset = nullptr;
}

inline Base::Base(const Base& cpy) :
    m_offset(new std::size_t(*(cpy.m_offset))),
    m_count(cpy.m_count),
    m_block(cpy.m_block)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

    if (m_count != nullptr) (*m_count)++;
}

inline Base::Base(Base&& mov) :
    m_offset(new std::size_t(*(mov.m_offset))),
    m_count(mov.m_count),
    m_block(std::move(mov.m_block))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    *(mov.m_offset) = 0;
    mov.m_count = nullptr;
    mov.m_block = Block{};
}

inline Base& Base::operator=(const Base& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    _Reset(m_count, m_block);
    *m_offset = *(cpy.m_offset);
    m_count = cpy.m_count;
    m_block = cpy.m_block;
    if (m_count != nullptr) (*m_count)++;
    return *this;
}

inline Base& Base::operator=(Base&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

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
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Allocation<%s>(flag=%d, type_size=%zu, type_count=%zu, defn=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(T),
            TEST_SYS_DEBUG_TV_TYPE(T(*)(), Func)),
        flag, type_size, type_count, defn);

    _Reset(m_count, m_block);
    *m_offset = 0;
    m_count = new CountType(1);
    return m_block.Allocation(flag, type_size, type_count, defn);
}

inline void Base::Deallocation()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Deallocation()");

    *m_offset = 0;
    _Reset(m_count, m_block);
}

template<typename T>
inline T* Base::Get()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Get<%s>()",
        TEST_SYS_DEBUG_TARGS_NAME_STR(T));

    const std::size_t size = m_block.GetDataSize();
    const std::size_t req_size = *m_offset + sizeof(T);
    if (req_size > size)
    {
        return test::sys::mem::Dummy::Get<T>();
    }
    char * data = (char *)m_block.GetData();
    return reinterpret_cast<T*>(data + *m_offset);
}

template<typename T>
inline T* Base::Get() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Get<%s>() const",
        TEST_SYS_DEBUG_TARGS_NAME_STR(T));

    const std::size_t size = const_cast<Block&>(m_block).GetDataSize();
    const std::size_t req_size = *m_offset + sizeof(T);
    if (req_size > size)
    {
        return test::sys::mem::Dummy::Get<T>();
    }
    char * data = (char *) const_cast<Block&>(m_block).GetData();
    return reinterpret_cast<T*>(data + *m_offset);
}

inline typename Base::FlagIntegerType Base::GetFlag() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetFlag() const");

    return const_cast<BlockType&>(m_block).GetFlag();
}

inline std::size_t Base::GetOffset() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetOffset() const");

    return *m_offset;
}

inline typename Base::IntegerCountType Base::GetCount() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetCount() const");

    return m_count == nullptr ? 0 : IntegerCountType(*m_count);
}

inline std::size_t Base::GetTypeSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetTypeSize() const");

    return const_cast<BlockType&>(m_block).GetTypeSize();
}

inline std::size_t Base::GetDataSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetDataSize() const");

    return const_cast<BlockType&>(m_block).GetDataSize();
}

inline void* Base::GetData()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetData()");

    return m_block.GetData();
}

inline void Base::SetOffset(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "SetOffset(size=%zu)", size);

    *m_offset = (size % GetDataSize());
}

inline Base& Base::operator+=(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(size=%zu)", size);

    if (GetDataSize() == 0) return *this;
    *m_offset += size;
    *m_offset %= GetDataSize();
    return *this;
}

inline Base& Base::operator-=(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(size=%zu)", size);

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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    *(this) += 1; 
    return *this;
}

inline Base Base::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Base ret{*this};
    *(this) += 1;
    return ret;
}

inline Base& Base::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    *(this) -= 1; 
    return *this;
}

inline Base Base::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Base ret{*this};
    *(this) -= 1; 
    return ret;
}

inline Base Base::operator+(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(size=%zu)", size);

    Base ret{*this};
    ret += size;
    return ret;
}

inline Base Base::operator-(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(size=%zu)", size);

    Base ret{*this};
    ret -= size;
    return ret;
}

inline bool Base::operator==(const Base& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p)", &other);

    return (const_cast<BlockType&>(m_block).GetData() == 
        const_cast<BlockType&>(other.m_block).GetData()) &&
        *m_offset == *(other.m_offset);
}

inline bool Base::operator!=(const Base& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p)", &other);
    
    return !(*this == other);
}

inline bool Base::operator==(void* other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p)", other);
    
    return const_cast<BlockType&>(m_block).GetData() == other;
}

inline bool Base::operator!=(void* other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p)", other);
    
    return const_cast<BlockType&>(m_block).GetData() != other;
}

inline Base::operator bool() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator bool() const");
    
    return const_cast<BlockType&>(m_block).GetData() != 
        BlockType{}.GetData();
}

} //!ptr

} //!test

#endif //!TEST_PTR_BASE_H_
