#ifndef TEST_OUT_CSTR_BASE_H_
#define TEST_OUT_CSTR_BASE_H_

#include "Status.h"
#include "../Interface.h"
#include "../../CString.h"
#include "../../def/cstr/val/Empty.h"

#include <cwchar>

namespace test
{
namespace out
{
namespace cstr
{

template<typename TChar>
class Base
{
public:
    typedef TChar CharType;
    typedef std::size_t SizeType; 
    typedef test::out::cstr::Status StatusType;
protected:
    static constexpr SizeType _Capacity(const SizeType & capacity,
        SizeType offset = (static_cast<SizeType>(-1) << 1));
    static SizeType _Predict(const SizeType & capacity, StatusType& status);
    static SizeType _Predict(const SizeType & capacity, 
        const SizeType & need_capacity, const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity, StatusType& status);
    static bool _Allocation(CharType * & cstr, SizeType& capacity, 
        const SizeType& new_capacity, StatusType& status);
    static bool _Reallocation(CharType * & cstr, SizeType& size, 
        SizeType & capacity, const SizeType& need_capacity, 
        const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity, StatusType& status);
    static bool _Initialize(CharType * &cstr, SizeType& size, 
        SizeType & capacity, SizeType & minimum_capacity, 
        SizeType & maximum_capacity, StatusType& status,
        const SizeType& new_capacity = static_cast<SizeType>(0));
    static void _Reset(CharType * &cstr, SizeType& size, 
        SizeType & capacity);
public:
    static constexpr SizeType default_maximum_capacity = 
        Base<TChar>::_Capacity(~(static_cast<SizeType>(-1) 
        << ((sizeof(SizeType) / 2) * 8)), (static_cast<SizeType>(-1) << 1));
    static constexpr SizeType default_minimum_capacity =
        Base<TChar>::_Capacity(~(static_cast<SizeType>(-1) 
        << (sizeof(SizeType))), (static_cast<SizeType>(-1) << 1));
private:
    StatusType m_status;
    CharType * m_cstr;
    SizeType m_size, m_capacity, m_minimum_capacity, 
        m_maximum_capacity;
protected:
    Base();
    Base(const SizeType & minimum_capacity);
    Base(const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity);
public:
    ~Base();
public:
    Base(const Base<TChar>& cpy);
    Base(Base<TChar>&& mov);
public:
    Base<TChar>& operator=(const Base<TChar>& cpy);
    Base<TChar>& operator=(Base<TChar>&& mov);
public:
    SizeType Size() const;
    SizeType Capacity() const;
    SizeType MaximumCapacity() const;
    SizeType MinimumCapacity() const;
protected:
    const CharType * GetCStr() const;
protected:
    SizeType _Set(const SizeType& index, const TChar * cstr, 
        const SizeType& size);
public:
    test::CString<TChar> Get() const; 
public:
    bool IsGood() const;
    bool IsBad() const;
    typename StatusType::ValueType GetBadCode() const;
protected:
    void Bad(const typename StatusType::ValueType& code);
public:
    bool Output(test::out::Interface<TChar>& out) const;
};


template<typename TChar>
constexpr typename Base<TChar>::SizeType 
Base<TChar>::_Capacity(const SizeType & capacity, SizeType offset)
{
    return offset != 0 ? ((~offset) >= capacity ? ~offset : 
        _Capacity(capacity, offset << 1)) : 0;
}

template<typename TChar>
typename Base<TChar>::SizeType
Base<TChar>::_Predict(const SizeType & capacity, StatusType& status)
{
    const SizeType res = _Capacity(capacity);
    if (res == static_cast<SizeType>(0)) 
        status.Bad(StatusType::overflow_capacity);
    return res;
}

template<typename TChar>
typename Base<TChar>::SizeType 
Base<TChar>::_Predict(const SizeType & capacity, 
    const SizeType & need_capacity, const SizeType & minimum_capacity, 
    const SizeType & maximum_capacity, StatusType& status)
{
    SizeType curr_capacity = (capacity == static_cast<SizeType>(0)) ?
        ~minimum_capacity : capacity;
    
    if (curr_capacity == need_capacity)
    {
        return curr_capacity;
    }
    else if (need_capacity < curr_capacity)
    {
        if (need_capacity < minimum_capacity) return minimum_capacity;
        SizeType curr = curr_capacity;
        while (true)
        {
            if (curr < need_capacity)
                return ~static_cast<SizeType>(~curr << 1);
            curr >>= 1;
        }
    }
    else
    {
        if (need_capacity > maximum_capacity) 
        {
            status.Bad(StatusType::overflow_capacity);
            return 0;
        }
        else if(need_capacity == maximum_capacity) return maximum_capacity;
        SizeType curr = ~curr_capacity;
        while(true)
        {
            const SizeType size = ~curr;
            if (size >= need_capacity)
                return size;
            curr <<= 1;
        }
    }
    status.Bad(StatusType::predict_failed);
    return 0;
}

template<typename TChar>
bool Base<TChar>::_Allocation(CharType * & cstr, SizeType& capacity, 
    const SizeType& new_capacity, StatusType& status)
{
    if (cstr != nullptr)
    {
        delete[] cstr;
        cstr = nullptr;
        capacity = static_cast<SizeType>(0);
    }
    if (new_capacity == static_cast<SizeType>(0)) 
    {
        status.Bad(StatusType::zero_allocation_failed);
        return false;
    }
    cstr = new CharType[new_capacity];
    capacity = new_capacity;
    
    if (cstr == nullptr)
    {
        status.Bad(StatusType::allocation_failed);
        return false;
    }

    return true;
}

template<typename TChar>
bool Base<TChar>::_Reallocation(CharType * & cstr, SizeType& size, 
    SizeType & capacity, const SizeType& need_capacity, 
    const SizeType & minimum_capacity, 
    const SizeType & maximum_capacity, StatusType& status)
{
    
    StatusType new_status;
    SizeType target_capacity = _Predict(capacity, need_capacity, 
        minimum_capacity, maximum_capacity, new_status);

    if (new_status.IsBad()) 
    {
        if (new_status.BadCode() == StatusType::overflow_capacity)
            status.Bad(StatusType::reallocation_overflow_capacity);
        else 
            status.Bad(StatusType::predict_reallocation_failed);
        return false;
    }

    if (capacity == target_capacity) return true;

    CharType * new_alloc = nullptr;
    SizeType new_alloc_capacity = 0;

    if (!_Allocation(new_alloc, new_alloc_capacity, 
        target_capacity, new_status)) 
    {
        status.Bad(StatusType::reallocation_failed);
        return false;
    }

    if (cstr != nullptr)
    {
        if (size == 0)
        {
            std::memset(new_alloc, 0, new_alloc_capacity * sizeof(CharType));
        }
        else if (new_alloc_capacity > size)
        {
            const SizeType num = size * sizeof(CharType);
            const SizeType num_diff = (new_alloc_capacity - size) *
                sizeof(CharType);
            std::memcpy(new_alloc, cstr, num);
            std::memset(new_alloc + num, 0, num_diff);
        }
        else if (new_alloc_capacity == size)
        {
            std::memcpy(new_alloc, cstr, size * sizeof(CharType));
            std::memset(new_alloc + (new_alloc_capacity - 1), 
                static_cast<CharType>(0), sizeof(CharType));
        }
        else
        {
            delete[] new_alloc;
            status.Bad(StatusType::copy_reallocation_failed);
            return false;
        }
        delete[] cstr;
    }
    else
    {
        std::memset(cstr, 0, new_alloc_capacity * sizeof(CharType));
    }

    cstr = new_alloc;
    new_alloc = nullptr;
    capacity = new_alloc_capacity;
    new_alloc_capacity = 0;

    return true;
}

template<typename TChar>
bool Base<TChar>::_Initialize(CharType * &cstr, SizeType& size, 
    SizeType & capacity, SizeType & minimum_capacity, 
    SizeType & maximum_capacity, StatusType& status,
    const SizeType& target_capacity)
{
    if (!status.IsRequire()) return true;
    if (status.IsRequireInitialize())
    {
        minimum_capacity = _Predict(minimum_capacity, status);
        if (status.IsBad()) return false;
        maximum_capacity = _Predict(maximum_capacity, status);
        if (status.IsBad()) return false;
        
        status.Unrequire(StatusType::require_initialize);
        status.Require(StatusType::require_allocation);
    }
    if (status.IsRequireAllocation())
    {
        SizeType _target_capacity = target_capacity;
        if (_target_capacity == static_cast<SizeType>(0))
            _target_capacity = minimum_capacity;
        if (!_Allocation(cstr, capacity, _target_capacity, status)) 
        {
            _Reset(cstr, size, capacity);
            return false;
        }
        std::memset(cstr, 0, capacity * sizeof(CharType));
        status.Unrequire(StatusType::require_allocation);
    }
    else if (status.IsRequireReallocation())
    {
        if (!_Reallocation(cstr, size, capacity, target_capacity, 
            minimum_capacity, maximum_capacity, status))
        {
            return false;
        }
        status.Unrequire(StatusType::require_reallocation);
    }
    return true;
}

template<typename TChar>
void Base<TChar>::_Reset(CharType * &cstr, SizeType& size, 
    SizeType & capacity)
{
    if (cstr) delete[] cstr;
    cstr = nullptr;
    capacity = 0;
    size = 0;
}

template<typename TChar>
Base<TChar>::Base() :
    m_status(),
    m_cstr(nullptr),
    m_size(0),
    m_capacity(0),
    m_minimum_capacity(default_minimum_capacity), 
    m_maximum_capacity(default_maximum_capacity)
{
    m_status.Require(StatusType::require_allocation);
    _Initialize(m_cstr, m_size, m_capacity, 
        m_minimum_capacity, m_maximum_capacity, m_status);
}

template<typename TChar>
Base<TChar>::Base(const SizeType & minimum_capacity)  :
    m_status(),
    m_cstr(nullptr),
    m_size(0),
    m_capacity(0),
    m_minimum_capacity(minimum_capacity), 
    m_maximum_capacity(default_maximum_capacity)
{
    m_status.Require(StatusType::require_initialize |
        StatusType::require_allocation);
    _Initialize(m_cstr, m_size, m_capacity, 
        m_minimum_capacity, m_maximum_capacity, m_status);
}

template<typename TChar>
Base<TChar>::Base(const SizeType & minimum_capacity, 
    const SizeType & maximum_capacity) :
        m_status(),
        m_cstr(nullptr),
        m_size(0),
        m_capacity(0),
        m_minimum_capacity(minimum_capacity), 
        m_maximum_capacity(maximum_capacity)
{
    m_status.Require(StatusType::require_initialize |
        StatusType::require_allocation);
    _Initialize(m_cstr, m_size, m_capacity, 
        m_minimum_capacity, m_maximum_capacity, m_status);
}

template<typename TChar>
Base<TChar>::~Base()
{
    _Reset(m_cstr, m_size, m_capacity);
    m_status.Reset();
    m_minimum_capacity = 0;
    m_maximum_capacity = 0;
}

template<typename TChar>
Base<TChar>::Base(const Base<TChar>& cpy) :
    m_status(),
    m_cstr(nullptr),
    m_size(0),
    m_capacity(0),
    m_minimum_capacity(cpy.m_minimum_capacity), 
    m_maximum_capacity(cpy.m_maximum_capacity)
{  
    m_status.Require(StatusType::require_allocation);
    if (_Initialize(m_cstr, m_size, m_capacity, 
        m_minimum_capacity, m_maximum_capacity,
        m_status, cpy.m_capacity))
    {
        std::memcpy(m_cstr, cpy.m_cstr, cpy.m_size * sizeof(CharType));
        std::memset(m_cstr + (cpy.m_size), static_cast<CharType>(0), 
            sizeof(CharType));
        m_size = cpy.m_size;
    }
}

template<typename TChar>
Base<TChar>::Base(Base<TChar>&& mov) :
    m_status(std::move(mov.m_status)),
    m_cstr(mov.m_cstr),
    m_size(mov.m_size),
    m_capacity(mov.m_capacity),
    m_minimum_capacity(mov.m_minimum_capacity), 
    m_maximum_capacity(mov.m_maximum_capacity)
{
    mov.m_cstr = nullptr;
    mov.m_status.Require(StatusType::require_allocation);
    mov.m_size = 0;
    mov.m_capacity = 0;
    mov.m_minimum_capacity = default_minimum_capacity;
    mov.m_maximum_capacity = default_maximum_capacity; 
}

template<typename TChar>
Base<TChar>& Base<TChar>::operator=(const Base<TChar>& cpy)
{
    m_status.Reset();
    m_status.Require(StatusType::require_reallocation);
    m_minimum_capacity = cpy.m_minimum_capacity; 
    m_maximum_capacity = cpy.m_maximum_capacity;
    if (_Initialize(m_cstr, m_size, m_capacity, 
        m_minimum_capacity, m_maximum_capacity, m_status, cpy.m_capacity))
    {
        std::memcpy(m_cstr, cpy.m_cstr, cpy.m_size * sizeof(CharType));
        std::memset(m_cstr + (cpy.m_size), static_cast<CharType>(0), 
            sizeof(CharType));
        m_size = cpy.m_size;
    }
    return *this;
}

template<typename TChar>
Base<TChar>& Base<TChar>::operator=(Base<TChar>&& mov)
{   
    m_cstr = mov.m_cstr;
    m_status = std::move(mov.m_status);
    m_size = mov.m_size;
    m_capacity = mov.m_capacity;
    m_minimum_capacity = mov.m_minimum_capacity;
    m_maximum_capacity = mov.m_maximum_capacity;

    mov.m_cstr = nullptr;
    mov.m_status.Require(StatusType::require_allocation);
    mov.m_size = 0;
    mov.m_capacity = 0;
    mov.m_minimum_capacity = default_minimum_capacity;
    mov.m_maximum_capacity = default_maximum_capacity; 
    return *this;
}

template<typename TChar>
typename Base<TChar>::SizeType Base<TChar>::Size() const
{
    return m_size;
}

template<typename TChar>
typename Base<TChar>::SizeType Base<TChar>::Capacity() const
{
    return m_capacity;
}

template<typename TChar>
typename Base<TChar>::SizeType Base<TChar>::MinimumCapacity() const
{
    return m_minimum_capacity;
}

template<typename TChar>
typename Base<TChar>::SizeType Base<TChar>::MaximumCapacity() const
{
    return m_maximum_capacity;
}

template<typename TChar>
const typename Base<TChar>::CharType * Base<TChar>::GetCStr() const
{
    return m_cstr;
}

template<typename TChar>
typename Base<TChar>::SizeType 
Base<TChar>::_Set(const SizeType& index, const TChar * cstr, 
    const SizeType& size)
{
    const SizeType req_size = index + size;
    SizeType target_capacity = req_size + 1;
    if ((req_size - index) != size || req_size > m_maximum_capacity)
    {
        m_status.Bad(StatusType::overflow_capacity);
        return 0;
    }
    if (req_size >= m_capacity)
    {
        if (!(m_status.IsRequireInitialize() ||
            m_status.IsRequireAllocation()))
        {
            m_status.Require(StatusType::require_reallocation);
        }
        else
        {
            target_capacity = _Predict(target_capacity, m_status);
            if (m_status.IsBad())
                return 0;
        }
    }
    if (_Initialize(m_cstr, m_size, m_capacity, 
        m_minimum_capacity, m_maximum_capacity, m_status, target_capacity))
    {
        std::memcpy(m_cstr + index, cstr, size * sizeof(CharType));
        std::memset(m_cstr + (m_capacity - 1), 
            static_cast<CharType>(0), sizeof(CharType));
        m_size = req_size;
        return size;
    }
    return 0;
}

template<typename TChar>
test::CString<TChar> Base<TChar>::Get() const
{
    if (m_status.IsRequire() || m_status.IsBad()) 
        return test::def::cstr::val::Empty::CStr<TChar>();
    return {m_cstr, m_size};
} 

template<typename TChar>
bool Base<TChar>::IsGood() const
{
    return m_status.IsGood() || 
        (!m_status.IsBad() && m_status.IsRequire());
}

template<typename TChar>
bool Base<TChar>::IsBad() const
{
    return m_status.IsBad();
}

template<typename TChar>
typename Base<TChar>::StatusType::ValueType 
Base<TChar>::GetBadCode() const
{
    return m_status.BadCode();
}

template<typename TChar>
void Base<TChar>::Bad(const typename StatusType::ValueType& code)
{
    m_status.Bad(code);
}

template<typename TChar>
bool Base<TChar>::Output(test::out::Interface<TChar>& out) const
{
    if (m_status.IsBad()) return false;
    const auto size = out.Puts(m_cstr, m_size);
    return size == m_size;
}

} //!cstr

} //!out

} //!test

#endif //!TEST_OUT_CSTR_BASE_H_
