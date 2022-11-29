#ifndef TEST_SYS_MEM_DUMMY_H_
#define TEST_SYS_MEM_DUMMY_H_

#include "../Interface.h"

#include <cstdlib>
#include <cstring>

namespace test
{
namespace sys
{
namespace mem
{

class Dummy
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
private:
    static inline Dummy& GetInstance();
public:
    static inline char* Get(const std::size_t n);
public:
    template<typename T>
    static inline T* Get();
public:
    static inline std::size_t Size();
public:
    char * m_alloc;
    std::size_t m_size;
private:
    inline Dummy();
public:
    Dummy(const Dummy&) = delete;
    Dummy(Dummy&&) = delete;
public:
    inline ~Dummy();
public:
    Dummy& operator=(const Dummy&) = delete;
    Dummy& operator=(Dummy&&) = delete;
private:
    inline char* GetAllocation(const std::size_t& n);
};

inline Dummy& Dummy::GetInstance()
{
    static Dummy instance;
    return instance;
}

inline char* Dummy::Get(const std::size_t n)
{
    if (n == 0)
    {
        return GetInstance().GetAllocation(1);
    }
    return GetInstance().GetAllocation(n);
}

template<typename T>
inline T* Dummy::Get()
{
    return reinterpret_cast<T*>(GetInstance().GetAllocation(sizeof(T)));
}

inline std::size_t Dummy::Size()
{
    return GetInstance().m_size;
}

inline Dummy::Dummy() :
    m_alloc(nullptr),
    m_size(0)
{}

inline Dummy::~Dummy()
{
    if (m_alloc != nullptr)
    {
        free(m_alloc);
        m_alloc = nullptr;
        m_size = 0;
    }
}

inline char* Dummy::GetAllocation(const std::size_t& n)
{
    static char heap = '\0';
    heap = '\0';
    const std::size_t& n1 = n + 1;
    if (n1 > m_size)
    {
        if (m_alloc == nullptr)
        {
            m_alloc = (char*)malloc(n1);
            if (m_alloc == nullptr)
            {
                SystemType::GetInstance().Error(
                    DefinitionType::Status::sMemRecordAllocFailed,
                    "Memory allocation is failed"
                );
                return &heap;
            }
        }
        else
        {
            m_alloc = (char *)realloc(m_alloc, n1);
            if (m_alloc == nullptr)
            {
                SystemType::GetInstance().Error(
                    DefinitionType::Status::sMemoryReallocFailed,
                    "Memory reallocation is failed"
                );
                return &heap;
            }
        }
        m_size = n1;
    }
    memset(m_alloc, 0, n1);
    return (m_alloc + 1);
}

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_DUMMY_H_
