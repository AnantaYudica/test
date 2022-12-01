#ifndef TEST_SYS_MEM_BLOCK_BASE_H_
#define TEST_SYS_MEM_BLOCK_BASE_H_

#include "../../Definition.h"
#include "../../Interface.h"

#include <cstddef>
#include <limits>
#include <utility>
#include <cstdlib>
#include <chrono>
#include <mutex>
#include <atomic>
#include <functional>
#include <type_traits>

namespace test
{
namespace sys
{
namespace mem
{
namespace block
{

class Base
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
public:
    typedef std::size_t IDType;
    typedef std::atomic_uint16_t StatusType;
    typedef std::uint16_t StatusIntegerType;
    typedef typename test::sys::Definition::TimestampType TimestampType;
    typedef std::function<std::size_t(void *& pointer)> ReallocateCallbackType;
public:
    struct Data
    {
        IDType id;
        void * pointer;
        std::size_t size;
        TimestampType alloc_timestamp;
        TimestampType dealloc_timestamp;
    };
    typedef bool(*DeallocationFuncType)(StatusIntegerType status, Data data) ;
public:
    static constexpr std::size_t EmptySize = 8;
public:
    static constexpr StatusIntegerType sGood = 0;
    static constexpr StatusIntegerType sDefaultConstructor = 1 | 2 | 4;
    static constexpr StatusIntegerType sNeedAllocate = 2 | 4;
    static constexpr StatusIntegerType sNullPointer = 2;
    static constexpr StatusIntegerType sZeroSize = 4;
    static constexpr StatusIntegerType sDeallocate = 8;
    static constexpr StatusIntegerType sBadAllocate = 16;
    static constexpr StatusIntegerType sRelocateNullpointer = 32;
    static constexpr StatusIntegerType sBadRelocateCallback = 128;
    static constexpr StatusIntegerType sReferenceCountOverflow = 256;
private:
    static bool DefaultDeallocation(StatusIntegerType status, Data data);
private:
    static void * Empty();
private:
    StatusType m_status;
    std::atomic_uint64_t m_refCount;
    std::mutex m_lock;
    DeallocationFuncType m_deallocator;
    Data m_data;
protected:
    inline Base();
    inline Base(const IDType& id);
    inline Base(const IDType& id, DeallocationFuncType deallocator);
protected:
    Base(const Base& cpy) = delete;
    Base(Base&& mov);
public:
    inline ~Base();
public:
    Base& operator=(const Base& cpy) = delete;
    inline Base& operator=(Base&& mov);
private:
    inline bool _Deallocate();
protected:
    inline bool Allocate(void* pointer, const std::size_t& size);
    inline bool Reallocate(ReallocateCallbackType callback);
    inline bool Deallocate();
    inline bool Release(const bool& force = false);
protected:
    inline bool SetDeallocator(DeallocationFuncType deallocator);
protected:
    inline void* Pointer();
    inline void* Pointer() const;
public:
    inline std::size_t Size() const;
    inline TimestampType AllocationTimestamp() const;
    inline TimestampType DeallocationTimestamp() const;
public:
    inline IDType ID() const;
public:
    inline std::size_t ReferenceCount() const;
    inline void AddReference() const;
    inline void ReleaseReference() const;
public:
    inline bool IsGood() const;
    inline bool IsBad() const;
public:
    inline StatusIntegerType Status() const;
public:
    inline operator bool() const;
public:
    inline bool operator==(const Base& other) const;
    inline bool operator!=(const Base& other) const;
};

inline bool Base::DefaultDeallocation(StatusIntegerType status, Data data)
{
    return true;
}

inline void * Base::Empty()
{
    static char _empty[EmptySize];
    return (void*)_empty;
}

inline Base::Base() :
    m_status(sDefaultConstructor),
    m_refCount(0),
    m_lock(),
    m_deallocator(DefaultDeallocation),
    m_data{0, Empty(), EmptySize, 0, 0}
{}

inline Base::Base(const IDType& id) :
        m_status(sNeedAllocate),
        m_refCount(0),
        m_lock(),
        m_deallocator(DefaultDeallocation),
        m_data{id, Empty(), EmptySize, 0, 0}
{}

inline Base::Base(const IDType& id, 
    DeallocationFuncType deallocator) :
        m_status(sNeedAllocate),
        m_refCount(0),
        m_lock(),
        m_deallocator(deallocator ? deallocator : DefaultDeallocation),
        m_data{id, Empty(), EmptySize, 0, 0}
{}

inline Base::Base(Base&& mov) :
    m_status(mov.m_status.load()),
    m_refCount(mov.m_refCount.load()),
    m_lock(),
    m_deallocator(mov.m_deallocator),
    m_data{mov.m_data.id, mov.m_data.pointer, mov.m_data.size,
        mov.m_data.alloc_timestamp, mov.m_data.dealloc_timestamp}
{
    mov.m_status.store(sDefaultConstructor);
    mov.m_refCount = 0;
    mov.m_deallocator = DefaultDeallocation;
    mov.m_data = Data{0, Empty(), EmptySize, 0, 0};
}

inline Base::~Base()
{
    {
        std::lock_guard<std::mutex> guard(m_lock);
        if (m_status.load() == sGood)
        {
            _Deallocate();
        }
    }

    this->m_status.store(0);
    this->m_refCount.store(0);
    this->m_data = Data{0, NULL, 0, 0, 0};
}

inline Base& Base::operator=(Base&& mov)
{
    m_status.store(mov.m_status.load());
    mov.m_status = sDefaultConstructor;

    m_refCount.store(mov.m_refCount.load());
    mov.m_refCount = 0;

    m_deallocator = mov.m_deallocator;
    mov.m_deallocator = DefaultDeallocation;

    m_data = Data{mov.m_data.id, mov.m_data.pointer, mov.m_data.size,
        mov.m_data.alloc_timestamp, mov.m_data.dealloc_timestamp};
    mov.m_data = Data{0, Empty(), EmptySize, 0, 0};

    return *this;
}

inline bool Base::_Deallocate()
{
    bool res = false;
    m_data.dealloc_timestamp = test::sys::Definition::GetTimestampNow();
    Data data{m_data.id, m_data.pointer, m_data.size,
        m_data.alloc_timestamp, m_data.dealloc_timestamp};
    if (m_deallocator == nullptr)
    {
        res = DefaultDeallocation(m_status.load(), data);
    }
    else
    {
        res = m_deallocator(m_status.load(), data);
    }

    if(res)
    {
        m_status.store(sDeallocate);
        m_data.pointer = Empty();
        m_data.size = EmptySize;
        m_refCount.store(0);
    }
    return res;
}

inline bool Base::Allocate(void* pointer, const std::size_t& size)
{
    if (pointer == nullptr || size == 0)
    {
        return false;
    }

    {
        std::lock_guard<std::mutex> guard(m_lock);
        if (m_data.pointer != Empty() || (m_status.load() & sNeedAllocate) !=
            sNeedAllocate)
        {
            return false;
        }
        
        m_data.alloc_timestamp = test::sys::Definition::GetTimestampNow();
        m_data.pointer = pointer;
        m_data.size = size;
        m_refCount = 1;
        m_status ^= sNeedAllocate;

        return true;
    }   
}

inline bool Base::Reallocate(ReallocateCallbackType callback)
{
    if(callback == nullptr)
    {
        m_status |= sBadRelocateCallback;
        return false;
    }
    {
        std::lock_guard<std::mutex> guard(m_lock);
        if (IsBad())
        {
            return false;
        }
        m_data.size = callback(m_data.pointer);
        if (m_data.pointer == nullptr)
        {

            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemBlockReallocationFailed, 
                "Memory Reallocation is failed");
            m_status |= sRelocateNullpointer;
            m_data.pointer = Empty();
            m_data.size = EmptySize;
            return false;
        }
    }

    return true;
}

inline bool Base::Deallocate()
{
    std::lock_guard<std::mutex> guard(m_lock);
    if (IsBad())
    {
        return false;
    }
    if (m_refCount.load() != 0)
    {
        return false;
    }
    return _Deallocate();
}

inline bool Base::Release(const bool& force)
{
    std::lock_guard<std::mutex> guard(m_lock);
    if (IsBad())
    {
        return false;
    }
    if (m_refCount.load() != 0 && !force)
    {
        return false;
    }
    
    return _Deallocate();
}

inline bool Base::SetDeallocator(DeallocationFuncType deallocator)
{
    if (m_deallocator != nullptr || 
        m_deallocator != &DefaultDeallocation || deallocator == nullptr)
    {
        return false;
    }
    {
        std::lock_guard<std::mutex> guard(m_lock);
        m_deallocator = deallocator;
    }
    return true;
}

inline void* Base::Pointer()
{
    void * pointer = nullptr;
    {
        const std::lock_guard<std::mutex> guard(m_lock);
        pointer = m_data.pointer;
    }
    return pointer;
}

inline void* Base::Pointer() const
{
    auto* cast_ptr = const_cast<Base*>(this);
    return cast_ptr->Pointer();
}

inline std::size_t Base::Size() const
{
    return m_data.size;
}

inline std::size_t Base::ReferenceCount() const
{
    return m_refCount.load();
}

inline typename Base::TimestampType 
Base::AllocationTimestamp() const
{
    return m_data.alloc_timestamp;
}

inline typename Base::TimestampType 
Base::DeallocationTimestamp() const
{
    return m_data.dealloc_timestamp;
}

inline typename Base::IDType Base::ID() const
{
    return m_data.id;
}

inline void Base::AddReference() const
{
    if (m_data.pointer == Empty()) return;
    auto* cast_ptr = const_cast<Base*>(this);
    if (cast_ptr->m_refCount < std::numeric_limits<std::size_t>::max())
    {
        cast_ptr->m_refCount += 1;
    }
    else
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemBlockReferenceCountOverflow, 
            "Memory Reference count is overflow");
    }
}

inline void Base::ReleaseReference() const
{
    auto* cast_ptr = const_cast<Base*>(this);
    std::lock_guard<std::mutex> guard(cast_ptr->m_lock);
    if (m_data.pointer == Empty()) return;
    if (m_refCount.load() != 1)
    {
        cast_ptr->m_refCount -= 1;
    }
    else
    {
        cast_ptr->m_refCount -= 1;
        if (m_status.load() == sGood)
        {
            cast_ptr->_Deallocate();
        }
        cast_ptr->m_status |= sDeallocate;
    }
}

inline bool Base::IsGood() const
{
    return m_status.load() == sGood;
}

inline bool Base::IsBad() const
{
    return m_status.load() != sGood;
}

inline typename Base::StatusIntegerType Base::Status() const
{
    return m_status.load();
}

inline Base::operator bool() const
{
    return m_data.pointer != Empty();
}

inline bool Base::operator==(const Base& other) const
{
    return m_data.id == other.m_data.id;
}

inline bool Base::operator!=(const Base& other) const
{
    return m_data.id != other.m_data.id;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_BASE_H_
