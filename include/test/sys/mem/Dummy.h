#ifndef TEST_SYS_MEM_DUMMY_H_
#define TEST_SYS_MEM_DUMMY_H_

#include "../Definition.h"
#include "../Interface.h"
#include "../Debug.h"

#include <cstdlib>
#include <cstring>

namespace test::sys::mem
{
class Dummy;
}

#ifndef TEST_SYS_MEM_DUMMY_DLEVEL

#define TEST_SYS_MEM_DUMMY_DLEVEL 2

#endif //!TEST_SYS_MEM_DUMMY_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_SYS_MEM_DUMMY_DLEVEL, 
    "test::sys::mem::Dummy", test::sys::mem::Dummy);

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
    typedef test::sys::dbg::Type<test::sys::mem::Dummy> DebugType;
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "GetInstance()");

    static Dummy instance;
    return instance;
}

inline char* Dummy::Get(const std::size_t n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "Get(n=%zu)", n);

    if (n == 0)
    {
        return GetInstance().GetAllocation(1);
    }
    return GetInstance().GetAllocation(n);
}

template<typename T>
inline T* Dummy::Get()
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 3, NULL, "Get<%s>()", 
        TEST_SYS_DEBUG_T_NAME_STR(T));

    return reinterpret_cast<T*>(GetInstance().GetAllocation(sizeof(T)));
}

inline std::size_t Dummy::Size()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "Size()");
    
    return GetInstance().m_size;
}

inline Dummy::Dummy() :
    m_alloc(nullptr),
    m_size(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
    
}

inline Dummy::~Dummy()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
    if (m_alloc != nullptr)
    {
        free(m_alloc);
        m_alloc = nullptr;
        m_size = 0;
    }
}

inline char* Dummy::GetAllocation(const std::size_t& n)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetAllocation(n=%zu)", n);
    
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
                    DefinitionType::Status::sMemDummyAllocationFailed,
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
                    DefinitionType::Status::sMemDummyReallocationFailed,
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
