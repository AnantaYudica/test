#ifndef TEST_OUT_CSTRING_H_
#define TEST_OUT_CSTRING_H_

#include "../CString.h"
#include "../cstr/Length.h"
#include "cstr/Status.h"
#include "Interface.h"

#include <cstddef>
#include <type_traits>
#include <cstring>
#include <utility>
#include <cstdarg>
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
namespace out
{

template<typename TChar = char>
class CString : public test::out::Interface<TChar>
{
public:
    typedef typename std::remove_cv<TChar>::type CharType;
    typedef std::size_t SizeType; 
    typedef test::out::cstr::Status StatusType;
public:
    static constexpr SizeType default_maximum_capacity = 
        CString<TChar>::_Capacity(~(static_cast<SizeType>(-1) 
        << ((sizeof(SizeType) / 2) * 8)));
    static constexpr SizeType default_minimum_capacity =
        CString<TChar>::_Capacity(~(static_cast<SizeType>(-1) 
        << (sizeof(SizeType))));
private:
    static constexpr SizeType _Capacity(const SizeType & capacity,
        SizeType offset = static_cast<SizeType>(-1) << 1);
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
private:
    StatusType m_status;
    CharType * m_cstr;
    SizeType m_size, m_capacity, m_minimum_capacity, 
        m_maximum_capacity;
public:
    CString();
    CString(const SizeType & minimum_capacity);
    CString(const SizeType & minimum_capacity, 
        const SizeType & maximum_capacity);
public:
    ~CString();
public:
    CString(const CString<TChar>& cpy);
    CString(CString<TChar>&& mov);
public:
    CString<TChar>& operator=(const CString<TChar>& cpy);
    CString<TChar>& operator=(CString<TChar>&& mov);
public:
    SizeType Size() const;
    SizeType Capacity() const;
    SizeType MaximumCapacity() const;
    SizeType MinimumCapacity() const;
private:
    SizeType _Set(const SizeType& index, const TChar * cstr, 
        const SizeType& size);
    SizeType _Set(const SizeType& index, const char * format, va_list var_args)
        __ATTRIBUTE__ ((__format__ (__printf__, 4, 0)));
public:
    SizeType VPrint(const char * format, va_list var_args) override;
    SizeType Print(const char * format, ...) override;
public:
    SizeType Puts(const TChar * cstr, const SizeType& size) override;
    SizeType Puts(const TChar * cstr) override;
    template<std::size_t S>
    SizeType Puts(const TChar(&cstr)[S]);
    SizeType Puts(const test::CString<TChar>& cstr) override;
    SizeType Puts(const test::CString<const TChar>& cstr) override;
    SizeType Puts(const CString<TChar>& cpy);
public:
    test::CString<TChar> Get() const; 
public:
    bool IsGood() const;
    bool IsBad() const;
    StatusType::ValueType GetBadCode() const;
public:
    bool Output(test::out::Interface<TChar>& out) const;
};

template<typename TChar>
constexpr typename CString<TChar>::SizeType 
CString<TChar>::_Capacity(const SizeType & capacity, SizeType offset)
{
    return offset != 0 ? ((~offset) >= capacity ? ~offset : 
        _Capacity(capacity, offset << 1)) : 0;
}

template<typename TChar>
typename CString<TChar>::SizeType
CString<TChar>::_Predict(const SizeType & capacity, StatusType& status)
{
    const SizeType res = _Capacity(capacity);
    if (res == static_cast<SizeType>(0)) 
        status.Bad(StatusType::overflow_capacity);
    return res;
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::_Predict(const SizeType & capacity, 
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
bool CString<TChar>::_Allocation(CharType * & cstr, SizeType& capacity, 
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
bool CString<TChar>::_Reallocation(CharType * & cstr, SizeType& size, 
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
bool CString<TChar>::_Initialize(CharType * &cstr, SizeType& size, 
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
void CString<TChar>::_Reset(CharType * &cstr, SizeType& size, 
    SizeType & capacity)
{
    if (cstr) delete[] cstr;
    cstr = nullptr;
    capacity = 0;
    size = 0;
}

template<typename TChar>
CString<TChar>::CString() :
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
CString<TChar>::CString(const SizeType & minimum_capacity)  :
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
CString<TChar>::CString(const SizeType & minimum_capacity, 
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
CString<TChar>::~CString()
{
    _Reset(m_cstr, m_size, m_capacity);
    m_status.Reset();
    m_minimum_capacity = 0;
    m_maximum_capacity = 0;
}

template<typename TChar>
CString<TChar>::CString(const CString<TChar>& cpy) :
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
CString<TChar>::CString(CString<TChar>&& mov):
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
CString<TChar>& CString<TChar>::operator=(const CString<TChar>& cpy)
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
CString<TChar>& CString<TChar>::operator=(CString<TChar>&& mov)
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
typename CString<TChar>::SizeType 
CString<TChar>::Size() const
{
    return m_size;
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::Capacity() const
{
    return m_capacity;
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::MinimumCapacity() const
{
    return m_minimum_capacity;
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::MaximumCapacity() const
{
    return m_maximum_capacity;
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::_Set(const SizeType& index, const TChar * cstr, 
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
typename CString<TChar>::SizeType 
CString<TChar>::_Set(const SizeType& index, const char * format, 
    va_list var_args)
{
    TChar * buffer = new TChar[m_minimum_capacity];
    
    int print_size = vsnprintf(buffer, m_minimum_capacity, format, var_args);
    
    if (print_size < 0) 
    {
        m_status.Bad(StatusType::print_buffer_failed);
        return 0;
    }

    if ((SizeType)print_size >= m_minimum_capacity)
    {
        delete[] buffer;
        buffer = new TChar[print_size + 1];
        auto print_res = vsnprintf(buffer, print_size + 1, 
            format, var_args);
        if (print_res < 0) 
        {
            m_status.Bad(StatusType::print_buffer_failed);
            return 0;
        }
    }

    const auto res = _Set(index, buffer, print_size);

    delete[] buffer;
    return res;
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::VPrint(const char * format, va_list var_args)
{
    if (m_status.IsBad()) return 0;
    return _Set(m_size, format, var_args);
}

template<typename TChar>
typename CString<TChar>::SizeType 
CString<TChar>::Print(const char * format, ...)
{
    if (m_status.IsBad()) return 0;
    va_list args;
    va_start(args, format);
    const auto res = _Set(m_size, format, args);
    va_end(args);
    return res;
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const TChar * cstr, const SizeType& size)
{
    if (m_status.IsBad()) return 0;
    if (cstr == nullptr || size == static_cast<SizeType>(0)) return 0;
    return _Set(m_size, cstr, size);
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const TChar * cstr)
{
    if (m_status.IsBad()) return 0;
    if (cstr == nullptr) return 0;
    const SizeType size = test::cstr::Length<TChar>::Value(cstr, 
        m_maximum_capacity - 1);
    if (size == 0) return 0;
    return _Set(m_size, cstr, size);
}

template<typename TChar>
template<std::size_t S>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const TChar(&cstr)[S])
{
    if (m_status.IsBad()) return 0;
    return _Set(m_size, cstr, S);
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const test::CString<TChar>& cstr)
{
    if (m_status.IsBad()) return 0;
    return _Set(m_size, *cstr, cstr.Size());
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const test::CString<const TChar>& cstr)
{
    if (m_status.IsBad()) return 0;
    return _Set(m_size, *cstr, cstr.Size());
}

template<typename TChar>
typename CString<TChar>::SizeType  
CString<TChar>::Puts(const CString<TChar>& cstr)
{
    if (m_status.IsBad()) return 0;
    return _Set(m_size, cstr.m_cstr, cstr.m_size);
}

template<typename TChar>
test::CString<TChar> CString<TChar>::Get() const
{
    if (m_status.IsRequire() || m_status.IsBad()) return {""};
    return {m_cstr, m_size};
} 

template<typename TChar>
bool CString<TChar>::IsGood() const
{
    return m_status.IsGood() || 
        (!m_status.IsBad() && m_status.IsRequire());
}

template<typename TChar>
bool CString<TChar>::IsBad() const
{
    return m_status.IsBad();
}

template<typename TChar>
typename CString<TChar>::StatusType::ValueType 
CString<TChar>::GetBadCode() const
{
    return m_status.BadCode();
}

template<typename TChar>
bool CString<TChar>::Output(test::out::Interface<TChar>& out) const
{
    if (m_status.IsBad()) return false;
    const auto size = out.Puts(m_cstr, m_size);
    return size == m_size;
}

} //!out

} //!test

#endif //!TEST_OUT_CSTRING_H_
