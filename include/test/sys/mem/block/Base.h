#ifndef TEST_SYS_MEM_BLOCK_BASE_H_
#define TEST_SYS_MEM_BLOCK_BASE_H_

#include "../../Definition.h"
#include "../../Log.h"

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

template<typename TSysStatus>
class Base
{
private:
    typedef TSysStatus SysStatusType;
    typedef test::sys::Log<SysStatusType> LogType;
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
    LogType& m_log;
    Data m_data;
protected:
    Base(LogType& log);
    Base(LogType& log, const IDType& id);
    Base(LogType& log, const IDType& id, DeallocationFuncType deallocator);
protected:
    Base(const Base<TSysStatus>& cpy) = delete;
    Base(Base<TSysStatus>&& mov);
public:
    ~Base();
public:
    Base<TSysStatus>& operator=(const Base<TSysStatus>& cpy) = delete;
    Base<TSysStatus>& operator=(Base<TSysStatus>&& mov);
private:
    bool _Deallocate();
protected:
    bool Allocate(void* pointer, const std::size_t& size);
    bool Reallocate(ReallocateCallbackType callback);
    bool Deallocate();
    bool Release(const bool& force = false);
protected:
    bool SetDeallocator(DeallocationFuncType deallocator);
protected:
    void* Pointer();
    void* Pointer() const;
public:
    std::size_t Size() const;
    TimestampType AllocationTimestamp() const;
    TimestampType DeallocationTimestamp() const;
public:
    IDType ID() const;
public:
    std::size_t ReferenceCount() const;
    void AddReference() const;
    void ReleaseReference() const;
public:
    bool IsGood() const;
    bool IsBad() const;
public:
    StatusIntegerType Status() const;
public:
    operator bool() const;
public:
    bool operator==(const Base& other) const;
    bool operator!=(const Base& other) const;
};

template<typename TSysStatus>
bool Base<TSysStatus>::DefaultDeallocation(StatusIntegerType status, Data data)
{
    return true;
}

template<typename TSysStatus>
void * Base<TSysStatus>::Empty()
{
    static char _empty[EmptySize];
    return (void*)_empty;
}

template<typename TSysStatus>
Base<TSysStatus>::Base(LogType& log) :
    m_status(sDefaultConstructor),
    m_refCount(0),
    m_lock(),
    m_deallocator(DefaultDeallocation),
    m_log(log),
    m_data{0, Empty(), EmptySize, 0, 0}
{}

template<typename TSysStatus>
Base<TSysStatus>::Base(LogType& log, const IDType& id) :
        m_status(sNeedAllocate),
        m_refCount(0),
        m_lock(),
        m_deallocator(DefaultDeallocation),
        m_log(log),
        m_data{id, Empty(), EmptySize, 0, 0}
{}

template<typename TSysStatus>
Base<TSysStatus>::Base(LogType& log, const IDType& id, 
    DeallocationFuncType deallocator) :
        m_status(sNeedAllocate),
        m_refCount(0),
        m_lock(),
        m_deallocator(deallocator ? deallocator : DefaultDeallocation),
        m_log(log),
        m_data{id, Empty(), EmptySize, 0, 0}
{}

template<typename TSysStatus>
Base<TSysStatus>::Base(Base&& mov) :
    m_status(mov.m_status.load()),
    m_refCount(mov.m_refCount.load()),
    m_lock(mov.m_lock),
    m_deallocator(mov.m_deallocator),
    m_log(mov.m_log),
    m_data{mov.m_data.id, mov.m_data.pointer, mov.m_data.size,
        mov.m_data.alloc_timestamp, mov.m_data.dealloc_timestamp}
{
    mov.m_status.store(sDefaultConstructor);
    mov.m_refCount = 0;
    mov.m_deallocator = DefaultDeallocation;
    mov.m_data = Data{0, Empty(), EmptySize, 0, 0};
}

template<typename TSysStatus>
Base<TSysStatus>::~Base()
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

template<typename TSysStatus>
Base<TSysStatus>& Base<TSysStatus>::operator=(Base<TSysStatus>&& mov)
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

template<typename TSysStatus>
bool Base<TSysStatus>::_Deallocate()
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

template<typename TSysStatus>
bool Base<TSysStatus>::Allocate(void* pointer, const std::size_t& size)
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

template<typename TSysStatus>
bool Base<TSysStatus>::Reallocate(ReallocateCallbackType callback)
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
            m_log.Error(TSysStatus::sMemoryReallocFailed, 
                "Memory Reallocation is failed");
            m_status |= sRelocateNullpointer;
            m_data.pointer = Empty();
            m_data.size = EmptySize;
            return false;
        }
    }

    return true;
}

template<typename TSysStatus>
bool Base<TSysStatus>::Deallocate()
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

template<typename TSysStatus>
bool Base<TSysStatus>::Release(const bool& force)
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

template<typename TSysStatus>
bool Base<TSysStatus>::SetDeallocator(DeallocationFuncType deallocator)
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

template<typename TSysStatus>
void* Base<TSysStatus>::Pointer()
{
    void * pointer = nullptr;
    {
        const std::lock_guard<std::mutex> guard(m_lock);
        pointer = m_data.pointer;
    }
    return pointer;
}

template<typename TSysStatus>
void* Base<TSysStatus>::Pointer() const
{
    auto* cast_ptr = const_cast<Base<TSysStatus>*>(this);
    return cast_ptr->Pointer();
}

template<typename TSysStatus>
std::size_t Base<TSysStatus>::Size() const
{
    return m_data.size;
}

template<typename TSysStatus>
std::size_t Base<TSysStatus>::ReferenceCount() const
{
    return m_refCount.load();
}

template<typename TSysStatus>
typename Base<TSysStatus>::TimestampType 
Base<TSysStatus>::AllocationTimestamp() const
{
    return m_data.alloc_timestamp;
}

template<typename TSysStatus>
typename Base<TSysStatus>::TimestampType 
Base<TSysStatus>::DeallocationTimestamp() const
{
    return m_data.dealloc_timestamp;
}

template<typename TSysStatus>
typename Base<TSysStatus>::IDType Base<TSysStatus>::ID() const
{
    return m_data.id;
}

template<typename TSysStatus>
void Base<TSysStatus>::AddReference() const
{
    if (m_data.pointer == Empty()) return;
    auto* cast_ptr = const_cast<Base<TSysStatus>*>(this);
    if (cast_ptr->m_refCount < std::numeric_limits<std::size_t>::max())
    {
        cast_ptr->m_refCount += 1;
    }
    else
    {
        m_log.Error(TSysStatus::sMemoryReferenceCountOverflow, 
            "Memory Reference count is overflow");
    }
}

template<typename TSysStatus>
void Base<TSysStatus>::ReleaseReference() const
{
    auto* cast_ptr = const_cast<Base<TSysStatus>*>(this);
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

template<typename TSysStatus>
bool Base<TSysStatus>::IsGood() const
{
    return m_status.load() == sGood;
}

template<typename TSysStatus>
bool Base<TSysStatus>::IsBad() const
{
    return m_status.load() != sGood;
}

template<typename TSysStatus>
typename Base<TSysStatus>::StatusIntegerType Base<TSysStatus>::Status() const
{
    return m_status.load();
}

template<typename TSysStatus>
Base<TSysStatus>::operator bool() const
{
    return m_data.pointer != Empty();
}

template<typename TSysStatus>
bool Base<TSysStatus>::operator==(const Base<TSysStatus>& other) const
{
    return m_data.id == other.m_data.id;
}

template<typename TSysStatus>
bool Base<TSysStatus>::operator!=(const Base<TSysStatus>& other) const
{
    return m_data.id != other.m_data.id;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_BASE_H_
