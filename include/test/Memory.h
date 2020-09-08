#ifndef TEST_MEMORY_H_
#define TEST_MEMORY_H_

#ifdef USING_TEST_MEMORY

#ifndef TEST_MEMORY_INIT_BLOCK_SIZE
#define TEST_MEMORY_INIT_BLOCK_SIZE 10
#endif //!TEST_MEMORY_INIT_BLOCK_SIZE

#ifndef TEST_MEMORY_MULTIPLY_BLOCK_SIZE
#define TEST_MEMORY_MULTIPLY_BLOCK_SIZE 10
#endif //!TEST_MEMORY_MULTIPLY_BLOCK_SIZE

#ifndef TEST_MEMORY_DEBUG_ALLOC
#define TEST_MEMORY_DEBUG_ALLOC 0
#endif //!TEST_MEMORY_DEBUG_ALLOC
#ifndef TEST_MEMORY_DEBUG_DEALLOC
#define TEST_MEMORY_DEBUG_DEALLOC 0
#endif //!TEST_MEMORY_DEBUG_DEALLOC

#include "mem/Block.h"
#include "Status.h"

#include <cstdio>

#ifndef __ATTRIBUTE__
#ifdef __GNUC__
#define __ATTRIBUTE__(...) __attribute__(__VA_ARGS__)
#else
#define __ATTRIBUTE__(...)
#endif
#endif //!__ATTRIBUTE__

namespace test
{

template<typename TStatus = test::Status>
class Memory final
{
public:
    typedef TStatus StatusType;
private:
    mem::Block* m_blocks;
    std::size_t m_blocksLength;
    std::size_t m_blocksSize;
    StatusType* m_status;
public:
    Memory(StatusType& status);
public:
    Memory(const Memory<TStatus>&) = delete;
    Memory(Memory<TStatus>&& mov);
public:
    ~Memory();
public:
    Memory<TStatus>& operator=(const Memory<TStatus>&) = delete;
    Memory<TStatus>& operator=(Memory<TStatus>&&) = delete;
public:
    void Set(StatusType& status);
private:
    void Info(const char* format, ...) 
        __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
    void Debug(const char* format, ...)
        __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
    void Error(const char* format, ...)
        __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
private:
    void ReallocationBlock();
    void AppendBlock(mem::Block& b);
public:
    void Register(void* p, const std::size_t s);
    template<std::size_t N>
    void Register(void* p, const std::size_t s,
        const char (&f)[N], const int& l);
    void Unregister(void * p);
    bool HasRegister(void * p);
};

template<typename TStatus>
Memory<TStatus>::Memory(StatusType& status) :
    m_blocks(nullptr),
    m_blocksLength(TEST_MEMORY_INIT_BLOCK_SIZE),
    m_blocksSize(0),
    m_status(&status)
{
    m_blocks = (mem::Block*)std::malloc(m_blocksLength * 
        sizeof(mem::Block));
    assert(m_blocks != NULL);
    const auto && _default = mem::Block();
    for (std::size_t i = 0; i < m_blocksLength; ++i)
        memcpy((void*)(m_blocks + i), (void*)&_default, sizeof(mem::Block));
    Debug("Memory Register Begin {length : %zu, size : %zu bytes}\n",
        m_blocksLength, m_blocksLength * sizeof(mem::Block));
}

template<typename TStatus>
Memory<TStatus>::Memory(Memory<TStatus>&& mov) :
    m_blocks(mov.m_blocks),
    m_blocksLength(mov.m_blocksLength),
    m_blocksSize(mov.m_blocksSize)
{
    mov.m_blocks = NULL;
    mov.m_blocksLength = 0;
    mov.m_blocksSize = 0;
}

template<typename TStatus>
Memory<TStatus>::~Memory()
{
    if (m_blocksLength != 0)
    {
        if (m_blocksSize != 0)
        {
            Debug("Memory Register {size : %zu}\n", m_blocksSize);
            for (std::size_t i = 0; i < m_blocksSize; ++i)
            {
                Error("Memory Block {addr : %p, size : %zu byte} "
                    "has not deallocation\n", (m_blocks + i)->Pointer(),
                    (m_blocks + i)->Size());
                if ((m_blocks + i)->File() != nullptr)
                {
                    Error(" in file %s, line %d\n",
                        (m_blocks + i)->File(), (m_blocks + i)->Line());
                }
            }
        }
        if (m_blocks != nullptr)
        {
            std::free(m_blocks);
            Debug("Memory Register End\n");
        }
    }
}

template<typename TStatus>
void Memory<TStatus>::Set(StatusType& status)
{
    assert(m_status == NULL);
    m_status = &status;
}

template<typename TStatus>
void Memory<TStatus>::Info(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

template<typename TStatus>
void Memory<TStatus>::Debug(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

template<typename TStatus>
void Memory<TStatus>::Error(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    m_status->Error();
}

template<typename TStatus>
void Memory<TStatus>::ReallocationBlock()
{
    if (m_blocksSize == m_blocksLength)
    {
        const auto old_length = m_blocksLength;
        m_blocksLength *= TEST_MEMORY_MULTIPLY_BLOCK_SIZE;
        mem::Block* new_blocks = (mem::Block*)std::malloc(m_blocksLength * 
            sizeof(mem::Block));
        if (new_blocks == NULL)
        {
            Error("Error Realloc {from %zu, byte to %zu bytes}\n", 
                old_length * sizeof(mem::Block), m_blocksLength * sizeof(mem::Block));
            m_blocksLength = old_length;
            return;
        }
        memcpy((void*) new_blocks, (void*) m_blocks, sizeof(mem::Block) * old_length);
        free(m_blocks);
        m_blocks = new_blocks;
        const auto && _default = mem::Block();
        for (std::size_t i = old_length; i < m_blocksLength; ++i)
            memcpy((void*)(m_blocks + i), (void*)&_default, sizeof(mem::Block));
        Debug("Memory Register Realloc {length : %zu, " 
            "size : %zu bytes}\n", m_blocksLength, 
            m_blocksLength * sizeof(mem::Block));
    }
}

template<typename TStatus>
void Memory<TStatus>::AppendBlock(mem::Block& b)
{
    if (!HasRegister(b.Pointer()))
    {
#if TEST_MEMORY_DEBUG_ALLOC
        Debug("alloc-memory {addr : %p, size : %zu bytes}\n",
                b.Pointer(), b.Size());
#endif
        *(m_blocks + m_blocksSize) = std::move(b);
        ++m_blocksSize; 
    }
    else
    {
        Error("Memory Register duplicate! {Addrs : %p}\n",
            b.Pointer());
    }
}

template<typename TStatus>
void Memory<TStatus>::Register(void* p, const std::size_t s)
{
    assert(p != NULL);
    assert(m_blocks != NULL);
    ReallocationBlock();
    mem::Block b(p, s);
    AppendBlock(b);
}

template<typename TStatus>
template<std::size_t N>
void Memory<TStatus>::Register(void* p, const std::size_t s,
    const char (&f)[N], const int& l)
{
    assert(p != NULL);
    assert(m_blocks != NULL);
    ReallocationBlock();
    mem::Block b(p, s, f, l);
    AppendBlock(b);
}

template<typename TStatus>
void Memory<TStatus>::Unregister(void * p)
{
    bool found = false;
    std::size_t iReplace = 0;
    for (std::size_t i = 0; i < m_blocksSize; ++i)
    {
        if (!found)
        {
            found = (p == (m_blocks + i)->Pointer());
            iReplace = i;
            if (found)
            {
#if TEST_MEMORY_DEBUG_DEALLOC
                Debug("dealloc-memory {addr : %p, "
                    "size : %zu bytes}\n", (m_blocks + i)->Pointer(),
                    (m_blocks + i)->Size());
#endif 
            }
        }
        else
        {
            *(m_blocks + iReplace++) =
                std::move(*(m_blocks + i));
        }
    }
    if (found) --m_blocksSize;
}

template<typename TStatus>
bool Memory<TStatus>::HasRegister(void * p)
{
    if (m_blocksSize == 0) return false;
    for (std::size_t i = 0; i < m_blocksSize; ++i)
    {
        if (p == (m_blocks + i)->Pointer())
            return true;
    }
    return false;
}

} //!test

#endif //!USING_TEST_MEMORY

#endif //!TEST_MEMORY_H_
